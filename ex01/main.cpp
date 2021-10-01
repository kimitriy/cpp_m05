# include "Bureaucrat.hpp"
# include "Form.hpp"

int	main()
{
	try
	{
		// Bureaucrat joe("Joe", 151);
		// std::cout << joe << std::endl;
		
		Bureaucrat bob("Bob", 16);
		std::cout << bob << std::endl;
		
		Form aaa("AAA", 15, 16);
		std::cout << aaa << std::endl;

		bob.promotion();
		std::cout << bob << std::endl;

		aaa.beSigned( bob );
		std::cout << aaa << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << F_R_RED << e.what() << RESET << std::endl;
	}
		
	return ( 0 );
}