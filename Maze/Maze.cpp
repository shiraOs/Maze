#include "Maze.h"

//ctor for maze
Maze::Maze(int hight, int width)
{
	int i, j;
	if (setHight(hight) && setWidth(width))
	{
		maze = new char*[hight];

		for (i = 0; i < hight; i++)
			maze[i] = new char[width];

		for (i = 0; i < hight; i++)
		{
			for (j = 0; j < width; j++)
			{
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

//d'tor for maze
Maze::~Maze()
{
	int i;
	for (i = 0; i < hight; i++)
		delete  maze[i];

	delete[] maze;
}

int Maze::getHight()
{
	return (this->hight);
}

int Maze::getWidth()
{
	return (this->width);
}

bool Maze::setHight(int hight)
{//for other main, checks the input.
	if ((hight > MAX_HIGHT && hight < 4) || hight % 2 == 0)
	{
		cout << "Hight needs to be an un-even number between 3-25" << endl;
		return false;
	}

	this->hight = hight;
	return true;
}

bool Maze::setWidth(int width)
{//for other main, checks the input.
	if ((width > MAX_WIDTH && width < 4) || width % 2 == 0)
	{
		cout << "Width needs to be an un-even number between 3-80" << endl;
		return false;
	}

	this->width = width;
	return true;
}

void Maze::create()
{//Creat a random maze by using stack
	Stack s1;
	int currMove[2], right[2], left[2], down[2], up[2];
	int *nextMove;
	int col= 1, row = 1, countRand, randValue;
	int* path[4];

	srand((unsigned)time(NULL));

	currMove[0] = row;
	currMove[1] = col;
	s1.Push(currMove);

	while (!s1.IsEmpty())
	{
		countRand = 0;										//count to know how many possible moves there are
		right[0] = right[1] = left[0] = left[1] = up[0] = up[1] = down[0] = down[1] = 0;	//reset all moves
		nextMove = s1.Pop();								//get the next move
		row = nextMove[0];
		col = nextMove[1];
		this->maze[row][col] = '$';							//mark for visit there
		
		if (((col + 2) < (this->getWidth() - 1)) && (this->maze[row][col + 2] == ' ')) //check move right
		{
			right[0] = row;
			right[1] = col + 2;
			path[countRand] = right;
			countRand++;
		}
		if (((row + 2) < this->getHight() - 1) && (this->maze[row + 2][col] == ' ')) //check move down
		{
			down[0] = row + 2;
			down[1] = col;
			path[countRand] = down;
			countRand++;
		}
		if (((col - 2) > 0) && (this->maze[row][col - 2] == ' '))					//check move left
		{
			left[0] = row;
			left[1] = col - 2;
			path[countRand] = left;
			countRand++;
		}
		if (((row - 2) > 0) && (this->maze[row - 2][col] == ' '))						//check move up
		{
			up[0] = row - 2;
			up[1] = col;
			path[countRand] = up;
			countRand++;
		}

		if (countRand != 0)
		{//there are moves
			randValue = rand() % countRand;
			nextMove[0] = path[randValue][0];
			nextMove[1] = path[randValue][1];

			if (nextMove[1] == col + 2)				//move right
				this->maze[row][col + 1] = ' ';
			else if (nextMove[1] == col - 2)		//move left
				this->maze[row][col - 1] = ' ';
			else if (nextMove[0] == row + 2)		//move down
				this->maze[row + 1][col] = ' ';
			else
				this->maze[row - 1][col] = ' ';		//move up

			s1.Push(currMove);						//push curr move
			s1.Push(nextMove);						//push next move
		}
		delete[] nextMove;
	}

	for (int i = 0; i < hight; i++)
		for (int j = 0; j < width; j++)
			if (this->maze[i][j] == '$')
				this->maze[i][j] = ' ';				//put space all places visit so maze will be empty to solve
}


bool Maze::solve()
{//Solve the maze using queue, retun true if solve, false otherwise
	Queue tor;
	int *currMove, *nextMove;
	bool flag = true;
	int row, col;

	nextMove = new int[2];
	nextMove[0] = 1;							//enter point (1,0)
	nextMove[1] = 0;							//enter point (1,0)

	tor.EnQueue(nextMove);						//push next move, start point

	while (!tor.isEmpty() && flag)				//as long as there are move
	{
		currMove = tor.DeQueue();
		row = currMove[0];			//get point to move
		col = currMove[1];			//get point to move
		this->maze[row][col] = '$';		//marking for visit

		if ((row == (this->getHight() - 2)) && (col == (this->getWidth() - 1)))
		{//check if exit point
			flag = false;
			this->maze[row][col] = '$';
		}
		else
		{
			if (((col + 1) <= (this->getWidth() - 1)) && (this->maze[row][col + 1] == ' ')) //move right
			{
				nextMove = new int[2];			//allocate new move
				nextMove[0] = row;
				nextMove[1] = col + 1;
				tor.EnQueue(nextMove);			//push next move to queue

			}
			if (((row + 1) < this->getHight() - 1) && (this->maze[row + 1][col] == ' ')) //move down
			{
				nextMove = new int[2];			//allocate new move
				nextMove[0] = row + 1;
				nextMove[1] = col;
				tor.EnQueue(nextMove);			//push next move to queue
			}
			if (((col - 1) > 0) && (this->maze[row][col - 1] == ' '))	//move left
			{
				nextMove = new int[2];			//allocate new move
				nextMove[0] = row;
				nextMove[1] = col - 1;
				tor.EnQueue(nextMove);			//push next move to queue
			}

			if (((row - 1) > 0) && (this->maze[row - 1][col] == ' '))	//move up
			{
				nextMove = new int[2];			//allocate new move
				nextMove[0] = row - 1;
				nextMove[1] = col;
				tor.EnQueue(nextMove);			//push next move to queue
			}
		}
	}

	if (this->maze[hight - 2][width - 1] == '$')	//check if marked visit at exit point-maze solved
		return true;
	else
		return false;
}

//Build your own maze using input from the keyboard
//Check if maze is good, meaning: only '*' and space chars are allowed,
//The frame can consists only '*', an opening point at 1,0 and an exit point at h-2,w-1.
bool Maze::buildMaze()
{
	char r[MAX_WIDTH+1];
	int i, j;
	cin.ignore();

	for (i = 0; i < this->getHight(); i++)
	{
		cin.getline(r, MAX_WIDTH + 1);

		if (strlen(r) != this->getWidth())		//lines not in same length as width entered
			return false; 

		for (j = 0; j < this->getWidth(); j++)	//write chars in maze only if valid- '*' or space
			if (r[j] == ' ')
				this->maze[i][j] = ' ';
			else if (r[j] == '*')
				this->maze[i][j] = '*';
			else
				return false;					//bad input, signes other then '*' or space
	}

	if (this->checkMaze())						//check frame, enter point and exit point
		return true;

	return false;
}


bool Maze::checkMaze()
{//check frame all '*', except space at enter point and exit point .
	int i, j;

	if ((maze[1][0] != ' ') && (maze[hight - 2][width - 1] != ' '))		//check enter and exit points
		return false;

	for (i = 0; i < this->hight; i++)									//check frame
	{
		for (j = 0; j < this->width; j++)	
		{

			if (maze[0][j] != '*')										//first row
				return false;
			if (maze[this->hight - 1][j] != '*')						// last row
				return false;
		}

		if (maze[i][0] != '*' && i != 1)								//first col except from enter point 1,0
			return false;
		if (maze[i][width - 1] != '*' && i != hight - 2)				//last col except frmo exit point h-2,w-1
			return false;
	}

	return true;					//nothing wrong
}

void Maze::print()
{//print the maze
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




