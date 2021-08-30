#include "ShrubberyCreationForm.hpp"

//default constructor/////////////////////////////////////////////////////////////
ShrubberyCreationForm::ShrubberyCreationForm( const std::string name, const int g2sign, const int g2exec )
	: Form( name, g2sign, g2exec )
{
	
}

//copy constructor////////////////////////////////////////////////////////////////
ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other )
	: Form( other )
{
	*this = other;
}

//destructor///////////////////////////////////////////////////////////////////////
ShrubberyCreationForm::~ShrubberyCreationForm( void )
{

}

//[=] operator overload/////////////////////////////////////////////////////////////
Form& ShrubberyCreationForm::operator= ( const ShrubberyCreationForm& other )
{
	if (this == &other)
		return ( *this );
	this->m_signed = other.getSigned();
	this->m_signedBy = other.getSignedBy();
	return ( *this );
}

//methods
void	ShrubberyCreationForm::plantTree( std::string target )
{
	std::string filename = target + "_shrubbery";
	std::ofstream ofs( filename ); //creates and opens file with name "filename", ofs - is an object of the ofstream class
	if (!ofs)
		throw FormException( "Unable to create file!" );
	
}