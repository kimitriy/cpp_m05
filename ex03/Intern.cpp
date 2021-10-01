#include "Intern.hpp"

//private
Form*	Intern::newShrubberyCreationForm( std::string target )
{
	Form *rv = new ShrubberyCreationForm( target );
	return ( rv );
}

Form*	Intern::newRobotomyRequestForm( std::string target )
{
	Form *rv = new RobotomyRequestForm( target );
	return ( rv );
}

Form*	Intern::newPresidentialPardonForm( std::string target )
{
	Form *rv = new PresidentialPardonForm( target );
	return ( rv );
}

//default constructor/////////////////////////////////////////////////////////////
Intern::Intern( void )
{
	std::cout << "Intern constructor started" << std::endl;
	fArr[0] = &Intern::newShrubberyCreationForm;
	fArr[1] = &Intern::newRobotomyRequestForm;
	fArr[2] = &Intern::newPresidentialPardonForm;
}

//copy constructor////////////////////////////////////////////////////////////////
Intern::Intern( const Intern& other )
{
	std::cout << "Intern constructor started" << std::endl;
	*this = other;
}

//destructor///////////////////////////////////////////////////////////////////////
Intern::~Intern( void )
{
	std::cout << "Intern destructor started" << std::endl;
	
	
}

//[=] operator overload/////////////////////////////////////////////////////////////
Intern& Intern::operator= ( const Intern& other )
{
	std::cout << "Intern [=] operator started" << std::endl;
	if (this != &other)
	{
		int	i = 0;
		while (i < 3)
		{
			this->fArr[i] = other.fArr[i];
			i++;
		}
	}
	return ( *this );
}


//exceptions/////////////////////////////////////////////////////////////////////
//constructor
Intern::InternException::InternException( const char *msg )
	: exception(), m_msg( msg )
{
	std::cout << "InternException constructor started" << std::endl;
}

//destructor
Intern::InternException::~InternException( void ) throw()
{
	std::cout << "InternException destructor started" << std::endl;
}

//method
const char* Intern::InternException::what( void ) const throw()
{
	return ( m_msg );
}

//methods//////////////////////////////////////////////////////////////////
Form* Intern::makeForm( std::string formName, std::string formTarget)
{
	std::string methodArr[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	Form* rv;
	int i = 0;
	while (i < 3)
	{
		if (methodArr[i].compare( formName ) == 0)
		{
			rv = (this->*fArr[i])( formTarget );
			// std::cout << "from makeForm: formTarget: " << formTarget << std::endl;
			return ( rv );
		}
		i++;
	}
	throw InternException( "Sorry! Requested form is unknown." );
}

//[<<] operator overload///////////////////////////////////////////////////
std::ostream& operator<< ( std::ostream& out, const Intern& intrn )
{
	( void )intrn;
	return ( out );
}