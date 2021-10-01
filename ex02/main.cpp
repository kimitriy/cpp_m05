#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	try
	{
		// Bureaucrat joe("Joe", 151);
		// std::cout << joe << std::endl;
		
		Bureaucrat bob("Bob", 6);
		std::cout << bob << std::endl;
		
		ShrubberyCreationForm aaa( "tree" );
		std::cout << aaa << std::endl;

		bob.promotion();
		std::cout << bob << std::endl;

		aaa.beSigned( bob );
		std::cout << aaa << std::endl;

		aaa.execute( bob );
		std::cout << aaa << std::endl;



		RobotomyRequestForm bbb( "noise" );
		std::cout << bbb << std::endl;

		bbb.beSigned( bob );
		std::cout << bbb << std::endl;

		bbb.execute( bob );
		std::cout << bbb << std::endl;



		PresidentialPardonForm ccc( "pardon" );
		std::cout << ccc << std::endl;

		ccc.beSigned( bob );
		std::cout << ccc << std::endl;

		ccc.execute( bob );
		std::cout << ccc << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << F_R_RED << e.what() << RESET << std::endl;
	}
		
	return ( 0 );
}