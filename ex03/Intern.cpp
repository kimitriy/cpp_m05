#include "Intern.hpp"

//default constructor/////////////////////////////////////////////////////////////
Intern::Intern( void )
{

}

//copy constructor////////////////////////////////////////////////////////////////
Intern::Intern( const Intern& other )
{
	*this = other;
}

//destructor///////////////////////////////////////////////////////////////////////
Intern::~Intern( void )
{

}

//[=] operator overload/////////////////////////////////////////////////////////////
Intern& Intern::operator= ( const Intern& other )
{
	if (this == &other)
		return ( *this );
	return ( *this );
}


//exceptions/////////////////////////////////////////////////////////////////////
//constructor
Intern::InternException::InternException( const char *msg )
	: exception(), m_msg( msg )
{

}

//destructor
Intern::InternException::~InternException( void ) throw()
{

}

//method
const char* Intern::InternException::what( void ) const throw()
{
	return ( m_msg );
}

//methods//////////////////////////////////////////////////////////////////
Form* Intern::makeForm( std::string formName, std::string formTarget)
{

}

//[<<] operator overload///////////////////////////////////////////////////
std::ostream& operator<< ( std::ostream& out, const Intern& intrn )
{
	return ( out );
}