# include "Bureaucrat.hpp"

//default constructor
Bureaucrat::Bureaucrat( std::string name, unsigned int grade )
	: m_name( name ), m_grade( grade )
{
	if ( m_grade < 1 )
		throw ( GradeTooHighException() );
	else if ( m_grade > 150 )
		throw ( GradeTooLowException() );
}

//copy constructor
Bureaucrat::Bureaucrat( const Bureaucrat& other )
{
	*this = other;
}

//destructor
Bureaucrat::~Bureaucrat( void )
{

}

//[=] operator overload
Bureaucrat& Bureaucrat::operator= ( const Bureaucrat& other )
{
	if (this == &other)
		return ( *this );
	this->m_grade = other.getGrade();
	return ( *this );
}

//getter
std::string		Bureaucrat::getName( void ) const
{
	return ( m_name );
}

unsigned int	Bureaucrat::getGrade( void ) const
{
	return ( m_grade );
}

//exceptions
std::exception&	Bureaucrat::GradeTooHighException()
{
	const char	*str = "The entered grade is too high and doesn't even exist";
	std::exception exc(str);
	exc.

	return (  );
}

std::exception&	Bureaucrat::GradeTooLowException()
{

}

//methods
void	Bureaucrat::promotion( void )
{
	
}

void	Bureaucrat::demotion( void )
{

}

//[<<] operator overload
std::ostream& operator<< ( std::ostream& out, const Bureaucrat& brcrt )
{
	out << brcrt.getName() << " bureaucrat grade " << brcrt.getGrade() << std::endl;
	return ( out );
}