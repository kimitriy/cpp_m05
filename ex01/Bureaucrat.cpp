#include "Bureaucrat.hpp"

//default constructor/////////////////////////////////////////////////////////////
Bureaucrat::Bureaucrat( std::string name, int grade )
	: m_name( name ), m_grade( grade )
{
	if ( m_grade < 1 )
		throw ( GradeTooHighException( "The grade can not be higher than 1! The bureaucrat hasn't been created!" ) );
	else if ( m_grade > 150 )
		throw ( GradeTooLowException( "The grade can not be lower than 150! The bureaucrat hasn't been created!" ) );
}

//copy constructor////////////////////////////////////////////////////////////////
Bureaucrat::Bureaucrat( const Bureaucrat& other )
{
	*this = other;
}

//destructor///////////////////////////////////////////////////////////////////////
Bureaucrat::~Bureaucrat( void )
{

}

//[=] operator overload/////////////////////////////////////////////////////////////
Bureaucrat& Bureaucrat::operator= ( const Bureaucrat& other )
{
	if (this == &other)
		return ( *this );
	this->m_grade = other.getGrade();
	return ( *this );
}


//exceptions/////////////////////////////////////////////////////////////////////
//constructor
Bureaucrat::GradeTooHighException::GradeTooHighException( const char *msg )
	: exception(), m_msg( msg )
{
	
}

//destructor
Bureaucrat::GradeTooHighException::~GradeTooHighException( void ) throw()
{

}

//method
const char* Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return ( m_msg );
}

//constructor
Bureaucrat::GradeTooLowException::GradeTooLowException( const char *msg )
	: exception(), m_msg( msg )
{
	
}

//destructor
Bureaucrat::GradeTooLowException::~GradeTooLowException( void ) throw()
{

}

//method
const char* Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return ( m_msg );
}

//getter/////////////////////////////////////////////////////////////////////
std::string		Bureaucrat::getName( void ) const
{
	return ( m_name );
}

int	Bureaucrat::getGrade( void ) const
{
	return ( m_grade );
}

//methods//////////////////////////////////////////////////////////////////
void	Bureaucrat::promotion( void )
{
	int	tmp = getGrade();
	if ( (tmp - 1) <= 0 )
		throw( GradeTooHighException( "The grade can not be higher than 1! Further promotion is unable!" ) );
	else
	{
		m_grade = --tmp;
		std::cout << F_R_GRN << "The bureaucrat " << F_R_PRPL << getName() << F_R_GRN << " is promoted. The grade is " << F_R_PRPL << getGrade() << F_R_GRN << " now." << RESET << std::endl;
	}
}

void	Bureaucrat::demotion( void )
{
	int	tmp = getGrade();
	if ( (tmp + 1) > 150 )
		throw( GradeTooHighException( "The grade can not be lower than 150! Further demotion is unable!" ) );
	else
	{
		m_grade = ++tmp;
		std::cout << F_R_GRN << "The bureaucrat " << F_R_PRPL << getName() << F_R_GRN << " is demoted. The grade is " << F_R_PRPL << getGrade() << F_R_GRN << " now." << RESET << std::endl;
	}
}

void	Bureaucrat::signForm( bool success, std::string form )
{
	if (success == true)
		std::cout << F_R_GRN << "Bureaucrat " << F_R_PRPL << this->getName() << F_R_GRN << " signs form " << F_R_PRPL << form << RESET << std::endl;
	else
		std::cout << F_R_GRN << "Bureaucrat " << F_R_PRPL << this->getName() << F_R_GRN << " cannot sign form " << F_R_PRPL << form << F_R_GRN << " because of " << F_R_PRPL << "inappropriate grade level" << RESET << std::endl;

}

//[<<] operator overload///////////////////////////////////////////////////
std::ostream& operator<< ( std::ostream& out, const Bureaucrat& brcrt )
{
	out << F_R_PRPL << brcrt.getName() << F_R_GRN << " bureaucrat grade " << F_R_PRPL << brcrt.getGrade() << RESET << std::endl;
	return ( out );
}