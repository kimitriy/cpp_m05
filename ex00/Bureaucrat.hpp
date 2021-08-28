#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "MyException.hpp"

# define RESET "\033[0m"

# define F_R_BLCK "\033[0;30m"
# define F_R_RED "\033[0;31m"
# define F_R_GRN "\033[0;32m"
# define F_R_YLLW "\033[0;33m"
# define F_R_BLU "\033[0;34m"
# define F_R_PRPL "\033[0;35m"
# define F_R_CYAN "\033[0;36m"
# define F_R_WHT "\033[0;37m"

class	Bureaucrat
{
	protected:
		const std::string	m_name;
		unsigned int		m_grade;

	public:
		//default constructor
		Bureaucrat( std::string name, unsigned int grade );

		//copy constructor
		Bureaucrat( const Bureaucrat& other );

		//destructor
		~Bureaucrat( void );

		//[=] operator overload
		Bureaucrat& operator= ( const Bureaucrat& other );

		class	GradeTooHighException : public std::exception
		{
			private:
				const char *m_msg;
			public:
				GradeTooHighException( const char *msg );
				~GradeTooHighException() throw();
				virtual const char *what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			private:
				const char *m_msg;
			public:
				GradeTooLowException( const char *msg );
				~GradeTooLowException() throw();
				virtual const char *what() const throw();
		};
		
		//getter
		std::string		getName( void ) const;
		unsigned int	getGrade( void ) const;

		//methods
		void	promotion( void );
		void	demotion( void );
};

//[<<] operator overload
std::ostream& operator<< ( std::ostream& out, const Bureaucrat& brcrt );

#endif