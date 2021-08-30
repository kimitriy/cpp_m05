#include <fstream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	public:	
		//default constructor
		ShrubberyCreationForm( const std::string name, const int g2sign, const int g2exec );

		//copy constructor
		ShrubberyCreationForm( const ShrubberyCreationForm& other );

		//destructor
		~ShrubberyCreationForm( void );

		//[=] operator overload
		Form& operator= ( const ShrubberyCreationForm& other );

		//methods
		void	plantTree( std::string target );
};