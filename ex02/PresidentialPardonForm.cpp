#include "PresidentialPardonForm.hpp"

//private
//method
void	PresidentialPardonForm::pardon( void ) const
{
	std::cout << F_R_PRPL << this->m_target << F_R_GRN << " has been pardoned by Zafod Beeblebrox." << RESET << std::endl;
}

//default constructor/////////////////////////////////////////////////////////////
PresidentialPardonForm::PresidentialPardonForm( const std::string target )
	: Form( "PresidentialPardonForm", 25, 5 ), m_target( target )
{
	
}

//copy constructor////////////////////////////////////////////////////////////////
PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other )
	: Form( other )
{
	*this = other;
}

//destructor///////////////////////////////////////////////////////////////////////
PresidentialPardonForm::~PresidentialPardonForm( void )
{

}

//[=] operator overload/////////////////////////////////////////////////////////////
Form& PresidentialPardonForm::operator= ( const PresidentialPardonForm& other )
{
	if (this == &other)
		return ( *this );
	this->setSigned( other.getSigned() );
	this->setSignedBy( other.getSignedBy() );
	this->m_target = other.m_target;
	return ( *this );
}

//methods
void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
	if ( this->getSigned() == false )
		throw ( FormException( "This PresidentialPardonForm is not signed yet! It must be signed before execution." ) );
	else
	{
		if ( executor.getGrade() <= this->getG2exec() ) //if executor's grade matches to the form requirements
		{
			std::cout << F_R_GRN << "Bureaucrat " << F_R_PRPL << executor.getName() << F_R_GRN << " executes " << F_R_PRPL << this->getName() << RESET << std::endl;
			pardon();
		}
		else
		{
			std::string anno = "Bureaucrat " + executor.getName() + " cannot execute the PresidentialPardonForm due to his grade level is unsufficient!";
			throw ( FormException( anno.c_str() ) );
		}
	}
}
