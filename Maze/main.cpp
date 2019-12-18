#include "Maze.h"

//Maze Creator and Solver
//by Alon Ben Harosh 312533698
//Shira ostrinsky 311119002
//Choose 1 to enter your own maze, or 2 to create a random maze.
//Then enter wanted higth (3-20) and width (3-80) of the maze: need to be odd number for random maze!
//If you chose 1: enter the string of chars with only: '*' for wall, or 'space' for blank
//The frame must be only '*' and spce for opening point at (1,0) and exit point at (hight-2,width-1)
//ENJOY!!!!

int main()
{
	int choice, h, w;

	cout << "Maze: 1) From input 2) Random" << endl;

	cin >> choice;
	cin >> h;
	cin >> w;
	cout << endl;
	
	if (h > MAX_HIGHT || h < 0 || w > MAX_WIDTH || w < 0)	//wrong input of hight and width
	{
		cout << "invalid input" << endl;
		exit(1);
	}
	
	Maze maze(h, w);			//build maze skeleton

	if (choice == 1)			//build user's own maze
	{
		if (maze.buildMaze() == false)
		{//exit for wrong input
			cout << "invalid input" << endl;
			exit(1);
		}
	}
	else if (choice != 2)		//exit if not one of the options
	{
		cout << "invalid input" << endl;
		exit(1);
	}
	else
	{//option 1
		if (h % 2 == 1 && w % 2 == 1)
			maze.create();				//build random maze for odd hight and width
		else
		{
			cout << "invalid input" << endl;
			exit(1);
		}
	}

	maze.print();
	
	if (maze.solve())				//try to solve
		maze.print();				//solve-print
	else
		cout << "no solution" << endl;

	system("pause");
}