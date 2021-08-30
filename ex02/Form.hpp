#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class	Form
{
	protected:
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
		~Form( void );

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

		// class	GradeTooLowException : public std::exception
		// {
		// 	private:
		// 		const char *m_msg;
		// 	public:
		// 		GradeTooLowException( const char *msg );
		// 		~GradeTooLowException( void ) throw();
		// 		virtual const char *what( void ) const throw();
		// };
		
		//setter
		void	setSigned( bool signature );
		void	setSignedBy( const Bureaucrat& brcrt );

		//getter
		const std::string	getName( void ) const;
		bool				getSigned( void ) const;
		int					getG2sign( void ) const;
		int					getG2exec( void ) const;
		std::string			getSignedBy( void ) const;

		//methods
		void	beSigned( Bureaucrat& brcrt );
};

//[<<] operator overload
std::ostream& operator<< ( std::ostream& out, const Form& form );

#endif