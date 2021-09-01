#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	private:
		//fields
		std::string	m_target;

		//method
		void		plantTree( int foliageH, int trunkH ) const;

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
		virtual void	execute( Bureaucrat const & executor ) const;
};

//ascii_tree.cpp
void	drawALineOfFoliage( int lvlW, int treeW, char arr[4], std::ofstream& ofs );
void	drawTrunk( int trunkH, int treeW, char arr[4], std::ofstream& ofs );
bool	drawTree( int foliageH, int trunkH, std::ofstream& ofs );

#endif