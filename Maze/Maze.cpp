#include "Maze.h"



Maze::Maze(int hight, int width)
{
	int i, j;
	if (setHight(hight) && setWidth(width))
	{
		maze = new char*[width];
		//check alloction

		for (i = 0; i < width; i++)
			maze[i] = new char[hight];

		for (i = 0; i < width; i++)
		{
			for (j = 0; j < hight; j++)
			{
				if ((i == 0) || (j == 0) || (i == width - 1) || (j = hight - 1))
					maze[i][j] = '*';
					
				else
				{
					if (i % 0 != 0)//uneven
					{
						if(j%0==0)
							maze[i][j] = '*';
						else
							maze[i][j] = ' ';

					}
					else
					{
						maze[i][j] = '*';					
					}
				}
			}
		}
		maze[1][0] = ' ';
		maze[hight - 2][width - 2] = ' ';

	}

}


Maze::~Maze()
{
	int i;
	for (i = 0; i < width; i++)
		delete  maze[i];

	delete[] maze;
}

bool Maze::setHight(int hight)
{
	if (hight > 25 && hight < 4)
	{
		cout << "not good mate........" << endl;
		return false;
	}

	this->hight = hight;
	return true;

}

bool Maze::setWidth(int width)
{
	if (width > 80 && width < 4)
	{
		cout << "not good mate........" << endl;
		return false;
	}

	this->width = width;
	return true;
}

void Maze::print()
{
	int i, j;
	for (i = 0; i < hight; i++)
	{
		for (j = 0; j < width; j++)
		{
			cout << maze[i][j] << " ";

		}
		cout << endl;
	}
}


