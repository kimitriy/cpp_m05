# include "Bureaucrat.hpp"

int	main()
{
	try
	{
		// // check constructor
		// Form m("m", 155, 1);
		// std::cout << m << std::endl;

		// // check constructor
		// Form m("m", 1, 200);
		// std::cout << m << std::endl;


		// check functions
		Bureaucrat John("John", 12);
		Bureaucrat Jack("Jack", 80);
		std::cout << John << std::endl;
		
		Form("csdc", 15, 20, 32);
		
		Form first("first", 13, 14);
		std::cout << first;
		Jack.signForm(first);
		John.signForm(first);
		Jack.signForm(first);
		John.signForm(first);
		std::cout << first;

		Form second("second", 11, 14);;
		std::cout << second;
		John.signForm(second);
		std::cout << second;
	}
	catch (std::exception & e)
	{
		std::cerr << F_R_RED << e.what() << RESET << '\n';
	}
		
	return ( 0 );
}