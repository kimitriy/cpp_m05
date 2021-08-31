#include "ShrubberyCreationForm.hpp"

//default constructor/////////////////////////////////////////////////////////////
ShrubberyCreationForm::ShrubberyCreationForm( const std::string target )
	: Form( "ShrubberyCreationForm", 145, 137 ), m_target( target )
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
	this->setSigned( other.getSigned() );
	this->setSignedBy( other.getSignedBy() );
	return ( *this );
}

//methods
void	ShrubberyCreationForm::plantTree()
{
	std::string filename = m_target + "_shrubbery";
	std::ofstream ofs( filename.c_str() ); //creates and opens file with name "filename", ofs - is an object of the ofstream class
	if ( !ofs )
		throw FormException( "Unable to create file!" );
	if ( drawTree(11, 2, ofs) == false )
		throw FormException( "Wrong value of foliage / trunk height!" );
	ofs.close();
}