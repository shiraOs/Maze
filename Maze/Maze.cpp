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
	if ((hight > 25 && hight < 4) || hight % 2 == 0)
	{
		cout << "not good mate........" << endl;
		return false;
	}

	this->hight = hight;
	return true;

}

bool Maze::setWidth(int width)
{
	if ((width > 80 && width < 4) || width % 2 == 0)
	{
		cout << "not good mate........" << endl;
		return false;
	}

	this->width = width;
	return true;
}



void Maze::create()
{
	Stack s1; 
	int temp[2],right[2],left[2],down[2],up[2];
	int* k;
	int kgo[2]; 
	int h, w,count,rad;
	int* path[4];
	
	h = 1;
	w = 1;
	srand((unsigned)time(NULL));
	temp[0] = h;
	temp[1] = w;
	s1.Push(temp);

	while (!s1.IsEmpty())
	{
		right[0] = right[1] = left[0] = left[1] = up[0] = up[1] = down[0] = down[1] = count = 0;
		k = s1.Pop();
		h = k[0];
		w = k[1];
		this->maze[h][w] = '$';
		if (((w + 2) < (this->getWidth() - 1)) && (this->maze[h][w + 2] == ' ')) //right
		{
			right[0] = h;
			right[1] = w + 2;
			path[count] = right;
			count++;

		}
		if (((h + 2) < this->getHight() - 1) && (this->maze[h + 2][w] == ' ')) //down
		{
			down[0] = h + 2;
			down[1] = w;
			path[count] = down;
			count++;
		}
		if (((w - 2) > 0) && (this->maze[h][w - 2] == ' '))//left
		{
			left[0] = h;
			left[1] = w - 2;
			path[count] = left;
			count++;
		}
		
		if (((h - 2) > 0) && (this->maze[h - 2][w] == ' ')) //up
		{
			up[0] = h - 2;
			up[1] = w;
			path[count] = up;
			count++;
		}
		//-----------------
		if (count != 0)
		{
			kgo[0] = k[0];
			kgo[1] = k[1]; //because rand delete k from some reason ?????
			rad = rand() % count;
			temp[0] = path[rad][0];
			temp[1] = path[rad][1];

			if (temp[1] == w + 2) //if right
				this->maze[h][w + 1] = ' ';
			else if (temp[1] == w - 2) // if left
				this->maze[h][w - 1] = ' ';
			else if (temp[0] == h + 2) //if down
				this->maze[h + 1][w] = ' ';
			else
				this->maze[h - 1][w] = ' '; //if up

			s1.Push(kgo);
			s1.Push(temp);
		}
			


	}		
	for (int i = 0; i < hight; i++)
		for (int j = 0; j < width; j++)
			if (this->maze[i][j] == '$')
				this->maze[i][j] = ' ';
}

void Maze::solve()
{
	Queue tor;
	int *cur,*temp;
	bool flag = true;
	int h, w;


	cur = new int[2];
	cur[0] = 1;
	cur[1] = 0;

	tor.EnQueue(cur);

	while (!tor.isEmpty() && flag)
	{
		temp = tor.DeQueue();
		this->maze[temp[0]][temp[1]] = '$';
		if ((temp[0] == this->getHight()) - 2 && temp[1] == (this->getWidth() - 1))
		{
			flag = false;
			this->maze[hight - 2][width - 1] = '$';
		}
		else
		{
			h = temp[0];
			w = temp[1];
			if (((w + 1) <= (this->getWidth() - 1)) && (this->maze[h][w + 1] == ' ')) //right
			{
				cur = new int[2];
				cur[0] = h;
				cur[1] = w+1;
				tor.EnQueue(cur);

			}
			if (((h + 1) < this->getHight() - 1) && (this->maze[h + 1][w] == ' ')) //down
			{
				cur = new int[2];
				cur[0] = h + 1;
				cur[1] = w;
				tor.EnQueue(cur);
			}
			if (((w - 1) > 0) && (this->maze[h][w - 1] == ' '))//left
			{
				cur = new int[2];
				cur[0] = h;
				cur[1] = w -1;
				tor.EnQueue(cur);
			}
		
			if (((h - 1) > 0) && (this->maze[h - 1][w] == ' ')) //up
			{
				cur = new int[2];
				cur[0] = h-1;
				cur[1] = w;
				tor.EnQueue(cur);
			}
		}
		cout << endl;
		
	}

	


}

bool Maze::buildMaze()
{

	bool res = true;
	char r[81];
	char ch;
	int i, j;
	cin.ignore();
	for (i = 0; i < this->getHight(); i++)
	{
		
		cin.getline(r, 80);
		
		for (j = 0; j < this->getWidth(); j++)
		{
			/*if (r[j] != ' ' && r[j] != '*')
				res = false;
			else */
			if (r[j] == ' ')
				this->maze[i][j] = ' ';
			else if (r[j] == '*')
				this->maze[i][j] = '*';
		}

		
	}
	
	if (res)
		if (this->checkMaze())
			return true;
	return false;
}

bool Maze::checkMaze()
{
	bool res = true;
	int i;
	
	for (i = 0; i < this->width; i++)
	{
		if (maze[0][i] != '*')
			return false;
		if (maze[this->hight-1][i] != '*')
			return false;
	}

	for (i = 0; i < this->hight; i++)
	{
		if ((maze[i][0] != '*') && (maze[i][0] != ' '))
			return false;
		else
			if (i == 1)
				if (maze[i][0] != ' ')
					return false;
		if ((maze[i][this->width - 1] != '*') && (maze[i][this->width - 1] != ' '))
			return false;
		else
			if (i == hight - 2)
				if (maze[i][width - 1] != ' ')
					return false;
	}
	return res;
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




