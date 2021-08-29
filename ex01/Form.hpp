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
		Form( std::string name, int g2sign, int g2exec );

		//copy constructor
		Form( const Form& other );

		//destructor
		~Form( void );

		//[=] operator overload
		Form& operator= ( const Form& other );

		class	GradeTooHighException : public std::exception
		{
			private:
				const char *m_msg;
			public:
				GradeTooHighException( const char *msg );
				~GradeTooHighException( void ) throw();
				virtual const char *what( void ) const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			private:
				const char *m_msg;
			public:
				GradeTooLowException( const char *msg );
				~GradeTooLowException( void ) throw();
				virtual const char *what( void ) const throw();
		};
		
		//setter
		std::string	setSignedBy(  )

		//getter
		const std::string	getName( void ) const;
		bool				getSigned( void ) const;
		const int			getG2sign( void ) const;
		const int			getG2exec( void ) const;
		std::string			getSignedBy( void ) const;

		//methods
		void	beSigned( const Bureaucrat& brcrt );
};

//[<<] operator overload
std::ostream& operator<< ( std::ostream& out, const Form& form );

#endif