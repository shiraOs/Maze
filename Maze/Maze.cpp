#include "Maze.h"


//ctor for maze
//put it at maze only if its good - if you dont follow the rules its the biggest maze
Maze::Maze(int hight, int width)
{
	int i, j;
	setHight(hight);
	setWidth(width); //put it at maze only if its good - if you dont follow the rules its the biggest maze

		maze = new char*[this->hight];
	if (!maze)
		exit(-100);

	for (i = 0; i < this->hight; i++)
		maze[i] = new char[this->width];

	for (i = 0; i < this->hight; i++)
	{
		for (j = 0; j < this->width; j++)
		{
			if ((i == this->hight - 1) || (j == this->width - 1) || (i % 2 == 0) || (j % 2 == 0))
				maze[i][j] = '*';
			else
				maze[i][j] = ' ';

		}
	}
	maze[1][0] = ' ';
	maze[this->hight - 2][this->width - 1] = ' ';

}

//d'tor for maze
Maze::~Maze()
{
	int i;
	for (i = 0; i < width; i++)
		delete  maze[i];

	delete[] maze;
}

//if you enter bad higth widht defalt is 79
bool Maze::setHight(int hight)
{
	if ((hight > 25 && hight < 4) || hight % 2 == 0)
	{
		cout << "Hight needs to be an un-even number between 3-25" << endl;
		this->hight = 19;
		return false;
	}

	this->hight = hight;
	return true;

}

//if you enter bad input widht defalt is 9
bool Maze::setWidth(int width)
{
	if ((width > 80 && width < 4) || width % 2 == 0)
	{
		cout << "Width needs to be an un-even number between 3-80" << endl;
		this->width = 79;
		return false;
	}

	this->width = width;
	return true;
}


//Creat a random maze by using stack 
void Maze::create()
{
	Stack s1; 
	int temp[2],right[2],left[2],down[2],up[2]; 
	int* val;
	int help[2]; 
	int h, w,count,rad;
	int* path[4];
	
	
	srand((unsigned)time(NULL)); // random as showen 
	temp[0] = h = 1;
	temp[1] = w = 1;
	s1.Push(temp);

	while (!s1.IsEmpty())
	{
		right[0] = right[1] = left[0] = left[1] = up[0] = up[1] = down[0] = down[1] = count = 0;
		val = s1.Pop();
		h = val[0];
		w = val[1];
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
			help[0] = val[0]; /// - for unknown reason val get deleted after using rand
			help[1] = val[1]; ///in the next line, couldnt explian why as it haven o interaction with val
			rad = rand() % count; // <==== this deletes val 
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

			s1.Push(help);
			s1.Push(temp);
		}
	}		
	for (int i = 0; i < hight; i++)
		for (int j = 0; j < width; j++)
			if (this->maze[i][j] == '$')
				this->maze[i][j] = ' ';
}

//Solve the maze using queue 
//retun true if solve, false otherwise
bool Maze::solve()
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
		
	}
	if (this->maze[hight - 2][width - 1] == '$') //if the path got to exit point
		return true;
	else
		return false; 

	


}

//Build your own maze using input from the keyboard
//checks if it good and return if so
bool Maze::buildMaze()
{

	char r[81];
	char ch;
	int i, j;
	cin.ignore();
	for (i = 0; i < this->getHight(); i++)
	{
		cin.getline(r, 80);
		if (strlen(r) != this->getWidth()) // to short or too long
			return false; //:)
		for (j = 0; j < this->getWidth(); j++)
			if (r[j] == ' ')
				this->maze[i][j] = ' ';
			else if (r[j] == '*')
				this->maze[i][j] = '*';
			else
				return false; //bad input
	}
	
	
	if (this->checkMaze())
		return true;
	return false;
}

//check if maze is good, meaning : only '*' and 'space' char are allawoed
//the perimeter most be only * and an opening point at 1,0 and h-2,w-1
bool Maze::checkMaze()
{
	bool res = true;
	int i,j;
	
	if ((maze[1][0] != ' ') &&(maze[hight-2][width-1] !=' ')) //enter and exit points
			return false;

	for (i = 0; i < this->hight; i++)
	{
		for (j = 0; j < this->width; j++)
		{
			if ((maze[i][j] != '*') && (maze[i][j] != ' ')) //bad input
				return false;
			if (maze[0][j] != '*') 
				return false;
			if (maze[this->hight - 1][j] != '*') 
				return false;							
		}

		if (maze[i][0] != '*')
			if (i != 1) // only enter point allowed not to be * 
				return false;
		if (maze[i][width - 1] != '*')
			if (i != hight - 2) // only enter point allowed not to be * 
				return false;
		
	}
	
	return res;
}

//print the maze
void Maze::print()
{
	int i, j;
	for (i = 0; i < hight; i++)
	{
		for (j = 0; j < width; j++)
			cout << maze[i][j] << " ";
		
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




