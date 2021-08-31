#include <fstream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	private:
		std::string	m_target;

	public:	
		//default constructor
		ShrubberyCreationForm( const std::string target );

		//copy constructor
		ShrubberyCreationForm( const ShrubberyCreationForm& other );

		//destructor
		~ShrubberyCreationForm( void );

		//[=] operator overload
		Form& operator= ( const ShrubberyCreationForm& other );

		//methods
		void	plantTree( void );
};

//ascii_tree.cpp
void	drawALineOfFoliage( int lvlW, int treeW, char arr[4], std::ofstream& ofs );
void	drawTrunk( int trunkH, int treeW, char arr[4], std::ofstream& ofs );
bool	drawTree( int foliageH, int trunkH, std::ofstream& ofs );
