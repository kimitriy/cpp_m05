#include <math.h>
#include "Form.hpp"

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
		~RobotomyRequestForm( void );

		//[=] operator overload
		Form& operator= ( const RobotomyRequestForm& other );

		//methods
		virtual void	execute( Bureaucrat const & executor ) const;
};