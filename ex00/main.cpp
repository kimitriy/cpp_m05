# include "Bureaucrat.hpp"

int	main()
{
	try
	{
		//check constructor 
		// Bureaucrat m("lala", 149);
		// std::cout << m << std::endl;
		// // m.promotion();
		// m.demotion();
		// m.demotion();

		//check constructor 
		// Bureaucrat m("lala", 155);
		// std::cout << m << std::endl;
		// std::cout << m.getName() << std::endl;
		// std::cout << m.getGrade() << std::endl;
		// m.promotion();

		// //check decrement
		// Bureaucrat m("lala", 149);
		// std::cout << m << std::endl;
		// m.demotion();
		// std::cout << m << std::endl;
		// m.demotion();

		// //check increment
		Bureaucrat t("tata", 1);
		std::cout << t << std::endl;
		Bureaucrat s(t);
		std::cout << s << std::endl;
		s.promotion();
	}
	catch (std::exception & e)
	{
		std::cerr << F_R_RED << e.what() << RESET << std::endl;
	}
		
	return ( 0 );
}