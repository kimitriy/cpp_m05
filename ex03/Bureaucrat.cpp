#include "Bureaucrat.hpp"
#include "Form.hpp"

//default constructor/////////////////////////////////////////////////////////////
Bureaucrat::Bureaucrat( std::string name, int grade )
	: m_name( name ), m_grade( grade )
{
	if ( m_grade < 1 )
		throw ( BureaucratException( "The grade can not be higher than 1! The bureaucrat hasn't been created!" ) );
	else if ( m_grade > 150 )
		throw ( BureaucratException( "The grade can not be lower than 150! The bureaucrat hasn't been created!" ) );
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
Bureaucrat::BureaucratException::BureaucratException( const char *msg )
	: exception(), m_msg( msg )
{
	
}

//destructor
Bureaucrat::BureaucratException::~BureaucratException( void ) throw()
{

}

//method
const char* Bureaucrat::BureaucratException::what( void ) const throw()
{
	return ( m_msg );
}

//getter/////////////////////////////////////////////////////////////////////
std::string	Bureaucrat::getName( void ) const
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
		throw( BureaucratException( "The grade can not be higher than 1! Further promotion is unable!" ) );
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
		throw( BureaucratException( "The grade can not be lower than 150! Further demotion is unable!" ) );
	else
	{
		m_grade = ++tmp;
		std::cout << F_R_GRN << "The bureaucrat " << F_R_PRPL << getName() << F_R_GRN << " is demoted. The grade is " << F_R_PRPL << getGrade() << F_R_GRN << " now." << RESET << std::endl;
	}
}

void	Bureaucrat::signForm( Form & form )
{
	form.beSigned( *this );
}

void	Bureaucrat::executeForm( Form const & form ) const
{
	form.execute( *this );
}

//[<<] operator overload///////////////////////////////////////////////////
std::ostream& operator<< ( std::ostream& out, const Bureaucrat& brcrt )
{
	out << F_R_PRPL << brcrt.getName() << F_R_GRN << " bureaucrat grade " << F_R_PRPL << brcrt.getGrade() << RESET << std::endl;
	return ( out );
}