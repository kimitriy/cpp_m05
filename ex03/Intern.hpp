#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class	Intern
{
	private:
		//fields
		typedef	Form* (Intern::*fPtrArr)( std::string target );
		fPtrArr	fArr[3];
		//methods
		Form	*newShrubberyCreationForm( std::string target );
		Form	*newRobotomyRequestForm( std::string target );
		Form	*newPresidentialPardonForm( std::string target );

	public:
		//default constructor
		Intern( void );

		//copy constructor
		Intern( const Intern& other );

		//destructor
		~Intern( void );

		//[=] operator overload
		Intern& operator= ( const Intern& other );

		class	InternException : public std::exception
		{
			private:
				const char *m_msg;
			public:
				InternException( const char *msg );
				~InternException( void ) throw();
				virtual const char *what( void ) const throw();
		};
		
		//setter

		//getter

		//methods
		Form *makeForm( std::string formName, std::string formTarget);
};

#endif