# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"

int	main()
{
	try
	{
		// Bureaucrat joe("Joe", 151);
		// std::cout << joe << std::endl;
		
		Bureaucrat bob("Bob", 137);
		std::cout << bob << std::endl;
		
		ShrubberyCreationForm aaa( "aaa" );
		std::cout << aaa << std::endl;

		// bob.promotion();
		// std::cout << bob << std::endl;

		aaa.beSigned( bob );
		std::cout << aaa << std::endl;

		aaa.execute( bob );
	}
	catch (std::exception & e)
	{
		std::cerr << F_R_RED << e.what() << RESET << '\n';
	}
		
	return ( 0 );
}