#include "Form.hpp"

//default constructor/////////////////////////////////////////////////////////////
Form::Form( const std::string name, const int g2sign, const int g2exec )
	: m_name( name ), m_signed( false ), m_g2sign( g2sign ), m_g2exec( g2exec ), m_signedBy( "\0" )
{
	if ( m_g2sign < 1 || m_g2exec < 1 )
		throw ( FormException( "Non of the grades can be higher than 1! The form hasn't been created!" ) );
	else if ( m_g2sign > 150 || m_g2exec > 150 )
		throw ( FormException( "Non of the grades can be lower than 150! The form hasn't been created!" ) );
}

//copy constructor////////////////////////////////////////////////////////////////
Form::Form( const Form& other )
	: m_name( other.getName() ), m_g2sign( other.getG2sign() ), m_g2exec( other.getG2exec() )
{
	*this = other;
}

//destructor///////////////////////////////////////////////////////////////////////
Form::~Form( void )
{

}

//[=] operator overload/////////////////////////////////////////////////////////////
Form& Form::operator= ( const Form& other )
{
	if (this == &other)
		return ( *this );
	this->m_signed = other.getSigned();
	this->m_signedBy = other.getSignedBy();
	return ( *this );
}


//exceptions/////////////////////////////////////////////////////////////////////
//constructor
Form::FormException::FormException( const char *msg )
	: exception(), m_msg( msg )
{

}

//destructor
Form::FormException::~FormException( void ) throw()
{

}

//method
const char* Form::FormException::what( void ) const throw()
{
	return ( m_msg );
}

//constructor
// Form::GradeTooLowException::GradeTooLowException( const char *msg )
// 	: exception(), m_msg( msg )
// {

// }

//destructor
// Form::GradeTooLowException::~GradeTooLowException( void ) throw()
// {

// }

//method
// const char* Form::GradeTooLowException::what( void ) const throw()
// {
// 	return ( m_msg );
// }

//setter
void	Form::setSigned( bool signature )
{
	m_signed = signature;
}

void	Form::setSignedBy( const Bureaucrat& brcrt )
{
	m_signedBy = brcrt.getName();
}

//getter/////////////////////////////////////////////////////////////////////
const std::string	Form::getName( void ) const
{
	return ( m_name );
}

bool	Form::getSigned( void ) const
{
	return ( m_signed );
}

int	Form::getG2sign( void ) const
{
	return ( m_g2sign );
}

int	Form::getG2exec( void ) const
{
	return ( m_g2exec );
}

std::string	Form::getSignedBy( void ) const
{
	return ( m_signedBy );
}

//methods//////////////////////////////////////////////////////////////////

void	Form::beSigned( Bureaucrat& brcrt )
{
	if ( brcrt.getGrade() <= this->getG2sign() )
	{
		setSigned( true );
		setSignedBy( brcrt );
		brcrt.signForm( true, this->getName() );
	}
	else
	{
		brcrt.signForm( false, this->getName() );
		throw ( FormException( "This bureaucrat cannot sign the form due to his grade level is unsufficient!" ) );
	}
}

//[<<] operator overload///////////////////////////////////////////////////
std::ostream& operator<< ( std::ostream& out, const Form& form )
{
	std::string status;
	if (form.getSigned() == true)
		status = "signed by " + form.getSignedBy();
	else
		status = "not signed yet";

	out << F_R_GRN << "Form " << F_R_PRPL << form.getName() << F_R_GRN << " requires ";
	out << F_R_PRPL << form.getG2sign() << F_R_GRN << " grade to sign and ";
	out << F_R_PRPL << form.getG2exec() << F_R_GRN << " grade to execute. ";
	out << F_R_GRN << "Current state: " << F_R_PRPL << status << RESET << std::endl;
	return ( out );
}