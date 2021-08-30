#include <iostream>
#include <string>

void	drawALineOfFoliage( int lvlW, int treeW )
{
	int	space = (treeW - lvlW) / 2;
	int i = -1;
	while ( ++i < space )
		std::cout << " ";
	i = -1;
	while ( ++i < (treeW - space * 2) )
		if ( i % 2 == 0)
			std::cout << "&";
		else
			std::cout << "$";
	i = -1;
	while ( ++i < space )
		std::cout << " ";
	std::cout << std::endl;
}

void	drawTrunk( int trunkH, int treeW )
{
	int	space = treeW / 2;
	int	h = 0;
	while ( h < trunkH )
	{
		int	i = -1;
		while ( ++i < space )
			std::cout << " ";
		std::cout << "#";
		i = -1;
		while ( ++i < space )
			std::cout << " ";
		std::cout << std::endl;
		h++;
	}
}

void drawTree( int foliageH, int trunkH )
{
	if ( foliageH <= 0 || trunkH <= 0)
	{
		std::cout << "Wrong value of foliage / trunk height!" << std::endl;
		return ;
	}
	int	treeW = 1;
	int lvlW = 1;
	int	i = 0;
	while (++i < foliageH)
		treeW += 2;
	i = 0;
	while ( ++i <= foliageH )
	{
		drawALineOfFoliage( lvlW, treeW );
		lvlW += 2;
	}
	drawTrunk( trunkH, treeW );
}

int	main()
{
	drawTree(17, 4);
	return ( 0 );
}