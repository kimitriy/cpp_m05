#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class	Form
{
	private:
		const std::string	m_name;
		bool				m_signed;
		const int			m_g2sign;
		const int			m_g2exec;
		std::string			m_signedBy;

	public:
		//default constructor
		Form( const std::string name, const int g2sign, const int g2exec );

		//copy constructor
		Form( const Form& other );

		//destructor
		virtual ~Form( void );

		//[=] operator overload
		Form& operator= ( const Form& other );

		class	FormException : public std::exception
		{
			private:
				const char *m_msg;
			public:
				FormException( const char *msg );
				~FormException( void ) throw();
				virtual const char *what( void ) const throw();
		};
		
		//setter
		void	setSigned( bool signature );
		void	setSignedBy( std::string name );

		//getter
		const std::string	getName( void ) const;
		bool				getSigned( void ) const;
		int					getG2sign( void ) const;
		int					getG2exec( void ) const;
		std::string			getSignedBy( void ) const;

		//methods
		void			beSigned( Bureaucrat & brcrt );
		virtual void	execute( Bureaucrat const & executor ) const = 0;
};

//[<<] operator overload
std::ostream& operator<< ( std::ostream& out, const Form& form );

#endif