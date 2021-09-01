#include "ShrubberyCreationForm.hpp"

void	drawALineOfFoliage( int lvlW, int treeW, char arr[4], std::ofstream& ofs )
{
	int	space = (treeW - lvlW) / 2;
	int i = -1;
	while ( ++i < space )
		ofs << arr[0];
	i = -1;
	while ( ++i < (treeW - space * 2) )
		if ( i % 2 == 0)
			ofs << arr[1];
		else
			ofs << arr[2];
	i = -1;
	while ( ++i < space )
		ofs << arr[0];
	ofs << std::endl;
}

void	drawTrunk( int trunkH, int treeW, char arr[4], std::ofstream& ofs )
{
	int	space = treeW / 2;
	int	h = 0;
	while ( h < trunkH )
	{
		int	i = -1;
		while ( ++i < space )
			ofs << arr[0];
		ofs << arr[3];
		i = -1;
		while ( ++i < space )
			ofs << arr[0];
		ofs << std::endl;
		h++;
	}
}

bool	drawTree( int foliageH, int trunkH, std::ofstream& ofs )
{
	char arr[4] = {' ', '&', '$', '#'};

	if ( foliageH <= 0 || trunkH <= 0)
		return ( false );
	int	treeW = 1;
	int lvlW = 1;
	int	i = 0;
	while (++i < foliageH)
		treeW += 2;
	i = 0;
	while ( ++i <= foliageH )
	{
		drawALineOfFoliage( lvlW, treeW, arr, ofs );
		lvlW += 2;
	}
	drawTrunk( trunkH, treeW, arr, ofs );
	return ( true );
}