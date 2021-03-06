#include "RobotomyRequestForm.hpp"

//private
//method
void	RobotomyRequestForm::robotomizer( int noise ) const
{
	int	i = 0;
	int rn;
	int	even = 0;
	
	while ( i < noise )
	{
		if ((rn = rand() % 2) == 0)
			even++;
		std::cout << F_R_YLLW << "Some drilling noise is making..." << RESET << std::endl;
		i++;
	}
	even = roundf( ((float)even / (float)noise) * 100 );
	std::cout << F_R_PRPL << this->m_target << F_R_GRN << " has been robotomized successfully " << F_R_PRPL << even << F_R_GRN << "\% of the time." << RESET << std::endl;
}

//default constructor/////////////////////////////////////////////////////////////
RobotomyRequestForm::RobotomyRequestForm( const std::string target )
	: Form( "RobotomyRequestForm", 72, 45 ), m_target( target )
{
	std::cout << "RobotomyRequestForm constructor started" << std::endl;
}

//copy constructor////////////////////////////////////////////////////////////////
RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other )
	: Form( other ), m_target(other.getTarget())
{
	std::cout << "RobotomyRequestForm copy constructor started" << std::endl;
}

//destructor///////////////////////////////////////////////////////////////////////
RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout << "RobotomyRequestForm destructor started" << std::endl;
}

//[=] operator overload/////////////////////////////////////////////////////////////
Form& RobotomyRequestForm::operator= ( const RobotomyRequestForm& other )
{
	std::cout << "RobotomyRequestForm [=] operator started" << std::endl;
	if (this == &other)
	{
		this->setSigned( other.getSigned() );
		this->setSignedBy( other.getSignedBy() );
		this->m_target = other.getTarget();
	}
	return ( *this );
}

//getter
std::string		RobotomyRequestForm::getTarget( void ) const
{
	return (m_target);
}

//methods
void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
	if ( this->getSigned() == false )
		throw ( FormException( "This RobotomyRequestForm is not signed yet! It must be signed before execution." ) );
	else
	{
		if ( executor.getGrade() <= this->getG2exec() ) //if executor's grade matches to the form requirements
		{
			std::cout << F_R_GRN << "Bureaucrat " << F_R_PRPL << executor.getName() << F_R_GRN << " executes " << F_R_PRPL << this->getName() << RESET << std::endl;
			robotomizer( 10 );
		}
		else
		{
			std::string anno = "Bureaucrat " + executor.getName() + " cannot execute the RobotomyRequestForm due to his grade level is unsufficient!";
			throw ( FormException( anno.c_str() ) );
		}
	}
}
