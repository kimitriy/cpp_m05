#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	try
	{
		// Bureaucrat joe("Joe", 151);
		// std::cout << joe << std::endl;
		
		
		Bureaucrat bob("Bob", 1);
		std::cout << bob << std::endl;
		
		Form *aaa = new ShrubberyCreationForm( "tree" );
		std::cout << *aaa << std::endl;

		// ShrubberyCreationForm bbb( "tree" );
		// std::cout << bbb << std::endl;

	
		// bob.promotion();
		// std::cout << bob << std::endl;

		aaa->beSigned( bob );
		std::cout << *aaa << std::endl;

		aaa->execute( bob );
		std::cout << *aaa << std::endl;

		delete aaa;

		/*
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
		*/

		// Intern	randomIntern;
		// Form*	randomForm;

		// randomForm = randomIntern.makeForm( "ShrubberyCreationForm", "Bender" );
		// randomForm = randomIntern.makeForm( "RobotomyRequestForm", "Bender" );
		// randomForm = randomIntern.makeForm( "PresidentialPardonForm", "Bender" );
		// randomForm = randomIntern.makeForm( "ccacaca", "Bender" );

		// std::cout << *randomForm << std::endl;

		// randomForm->beSigned( bob );
		// std::cout << *randomForm << std::endl;
		// randomForm->execute( bob );
		
		// delete randomForm;
	}
	catch (std::exception & e)
	{
		std::cerr << F_R_RED << e.what() << RESET << '\n';
	}
		
	return ( 0 );
}