#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form
{
	private:
		//fields
		std::string	m_target;

		//method
		void	pardon( void ) const;

	public:	
		//default constructor
		PresidentialPardonForm( const std::string target );

		//copy constructor
		PresidentialPardonForm( const PresidentialPardonForm& other );

		//destructor
		~PresidentialPardonForm( void );

		//[=] operator overload
		Form& operator= ( const PresidentialPardonForm& other );

		//methods
		virtual void	execute( Bureaucrat const & executor ) const;
};

#endif