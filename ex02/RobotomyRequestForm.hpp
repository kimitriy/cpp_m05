#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <math.h>
# include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private:
		//fields
		std::string	m_target;

		//method
		void	robotomizer( int noise ) const;

	public:	
		//default constructor
		RobotomyRequestForm( const std::string target );

		//copy constructor
		RobotomyRequestForm( const RobotomyRequestForm& other );

		//destructor
		virtual ~RobotomyRequestForm( void );

		//[=] operator overload
		Form& operator= ( const RobotomyRequestForm& other );
		
		//getter
		std::string		getTarget( void ) const;

		//methods
		virtual void	execute( Bureaucrat const & executor ) const;
};

#endif