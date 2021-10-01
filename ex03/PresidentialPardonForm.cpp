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
	std::cout << "PresidentialPardonForm constructor started" << std::endl;
}

//copy constructor////////////////////////////////////////////////////////////////
PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other )
	: Form( other ), m_target(other.getTarget())
{
	std::cout << "PresidentialPardonForm copy constructor started" << std::endl;
}

//destructor///////////////////////////////////////////////////////////////////////
PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout << "PresidentialPardonForm destructor started" << std::endl;
}

//[=] operator overload/////////////////////////////////////////////////////////////
Form& PresidentialPardonForm::operator= ( const PresidentialPardonForm& other )
{
	std::cout << "PresidentialPardonForm [=] operator started" << std::endl;
	if (this == &other)
	{
		this->setSigned( other.getSigned() );
		this->setSignedBy( other.getSignedBy() );
		this->m_target = other.getTarget();
	}
	return ( *this );
}

//getter
std::string		PresidentialPardonForm::getTarget( void ) const
{
	return (m_target);
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
