#ifndef MYEXCEPTION_HPP
# define MYEXCEPTION_HPP

# include <string>
# include <exception>

class	MyException : public std::exception
{
	private:

	public:
		//default constructor
		MyException( const char *msg );

		//destructor
		~MyException( void );
};

#endif