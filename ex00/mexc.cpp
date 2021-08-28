#include <iostream>
#include <string>
#include <exception>

class MyException : public std::exception
{
	private:
		const char	*m_msg;
	
	public:
		MyException(const char *msg)
			: exception(), m_msg( msg )
		{

		}

		~MyException() throw()
		{

		}

		virtual const char *what() const throw()
		{
			return ( m_msg );
		}
};

void foo(int	value)
{
	if (value == 1)
	{
		throw MyException( "This is my own what() he he he" );
		std::cout << "value = " << value << std::endl;
	}
}

int	main()
{
	try
	{
		foo(1);
	}
	catch(std::exception& exc)
	{
		std::cout << "MyException is caught " << exc.what() << std::endl;
	}
	return (0);
}