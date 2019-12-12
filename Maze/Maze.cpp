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
	int temp[2],right[2],left[2],down[2],up[2];
	int* k;
	int h, w,count,rad;
	int* path[4];


	h = 1;
	w = 1;

	temp[0] = h;
	temp[1] = w;

	

	s1.Push(temp);

	while (!s1.IsEmpty())
	{
		right[0] = right[1] = left[0] = left[1] = up[0] = up[1] = down[0] = down[1] = count = 0;
		k = s1.Pop();
		h = k[0];
		w = k[1];
		shira.maze[h][w] = '$';	

		if (((w + 2) < (shira.getWidth() - 1)) && (shira.maze[h][w + 2] == ' '))
		{
			right[0] = h;
			right[1] = w + 2;
			path[count] = right;
			count++;
			
		}
		if (((w - 2) > 0) && (shira.maze[h][w - 2] == ' '))
		{
			left[0] = h;
			left[1] = w -2;
			path[count] = left;
			count++;
		}
		if (((h + 2) < shira.getHight() - 1) && (shira.maze[h + 2][w] == ' '))
		{
			down[0] = h + 2;
			down[1] = w;
			path[count] = down;
			count++;
		}
		if (((h - 2) > 0) && (shira.maze[h - 2][w] == ' '))
		{
			up[0] = h - 2;
			up[1] = w;
			path[count] = up;
			count++;
		}
		
		rad = rand() % count;
		temp[0] = path[rad][0];
		temp[1] = path[rad][1];

		if (temp[1] == w + 2) //if right
			shira.maze[h][w + 1] = ' ';



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


int Maze::getHight()
{
	return (this->hight);
}

int Maze::getWidth()
{
	return (this->width);
}


