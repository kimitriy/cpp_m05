#include "ShrubberyCreationForm.hpp"

//private
//method
void	ShrubberyCreationForm::plantTree( int foliageH, int trunkH ) const
{
	std::string filename = m_target + "_shrubbery";
	std::ofstream ofs( filename.c_str() ); //creates and opens file with name "filename", ofs - is an object of the ofstream class
	if ( !ofs )
		throw FormException( "Unable to create file!" );
	if ( drawTree( foliageH, trunkH, ofs) == false )
		throw FormException( "Wrong value of foliage / trunk height!" );
	ofs.close();
	std::cout << F_R_PRPL << filename << F_R_GRN << " has been created successfully " << RESET << std::endl;
}

//default constructor/////////////////////////////////////////////////////////////
ShrubberyCreationForm::ShrubberyCreationForm( const std::string target )
	: Form( "ShrubberyCreationForm", 145, 137 ), m_target( target )
{
	std::cout << "ShrubberyCreationForm constructor started" << std::endl;
}

//copy constructor////////////////////////////////////////////////////////////////
ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other )
	: Form( other ), m_target(other.getTarget())
{
	std::cout << "ShrubberyCreationForm copy constructor started" << std::endl;
}

//destructor///////////////////////////////////////////////////////////////////////
ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << "ShrubberyCreationForm destructor started" << std::endl;
}

//[=] operator overload/////////////////////////////////////////////////////////////
Form& ShrubberyCreationForm::operator= ( const ShrubberyCreationForm& other )
{
	std::cout << "ShrubberyCreationForm [=] operator started" << std::endl;
	if (this == &other)
	{
		this->setSigned( other.getSigned() );
		this->setSignedBy( other.getSignedBy() );
		this->m_target = other.getTarget();
	}
	return ( *this );
}

//getter
std::string		ShrubberyCreationForm::getTarget( void ) const
{
	return (m_target);
}

//methods
void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
	if ( this->getSigned() == false )
		throw ( FormException( "This ShrubberyCreationForm is not signed yet! It must be signed before execution." ) );
	else
	{
		if ( executor.getGrade() <= this->getG2exec() ) //if executor's grade matches to the form requirements
		{
			std::cout << F_R_GRN << "Bureaucrat " << F_R_PRPL << executor.getName() << F_R_GRN << " executes " << F_R_PRPL << this->getName() << RESET << std::endl;
			plantTree( 11, 2 );
		}
		else
		{
			std::string anno = "Bureaucrat " + executor.getName() + " cannot execute the ShrubberyCreationForm due to his grade level is unsufficient!";
			throw ( FormException( anno.c_str() ) );
		}
	}
}
