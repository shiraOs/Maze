#include "Maze.h"



Maze::Maze(int hight, int width)
{
	int i, j;
	if (setHight(hight) && setWidth(width))
	{
		maze = new char*[hight];
		//check alloction

		for (i = 0; i < hight; i++)
			maze[i] = new char[width];

		for (i = 0; i < hight; i++)
		{
			for (j = 0; j < width; j++)
			{
				//if ((i == 0) || (j == 0) || (i == hight - 1) || (j == width - 1))
				//	maze[i][j] = '*';
				//else
				//{
				//	if (i % 2 != 0)//uneven
				//	{
				//		if (j % 2 == 0)
				//			maze[i][j] = '*';
				//		else
				//			maze[i][j] = ' ';
				//	}
				//	else
				//		maze[i][j] = '*';
				//}
				if ((i == hight - 1) || (j == width - 1) || (i % 2 == 0) || (j % 2 == 0))
					maze[i][j] = '*';
				else
					maze[i][j] = ' ';
				
			}
		}
		maze[1][0] = ' ';
		maze[hight - 2][width - 1] = ' ';
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

void Maze::create(Maze shira)
{
	Stack s1; 
	char temp;
	int h, w;

	h = 1;
	w = 1;

	s1.Push(shira.maze[h][w]);

	while (!s1.IsEmpty())
	{
		temp = s1.Pop();
	}

	
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


