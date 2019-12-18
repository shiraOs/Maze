#include "Maze.h"

//Maze Creator and Solver
//by Alon Ben Harosh
//Shira ostrinsky 311119002
//Choose 1 to enter your own maze by and 2 for the Random Creation of a maze
//after that enter your higth(3-20) and width(3-80) of the maze: an un-even number
//if your choose 1: enter the string of chars with only: '*' for wall, or 'space' for blank
//the perimeter most be only * and an opening point at 1,0 and h-2,w-1
//enjoy!!!!

const int MAX_HIGHT = 25;
const int MAX_WIDTH = 80;

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
	
	Maze maze(h, w);

	if (choice == 1)			//build his own maze
	{
		if (maze.buildMaze() == false)
		{
			cout << "invalid input" << endl;
			exit(1);
		}
	}
	else if (choice != 2)		//not one of the options
	{
		cout << "invalid input" << endl;
		exit(1);
	}
	else
	{
		if (h % 2 == 1 && w % 2 == 1)
			maze.create();				//build random maze
		else
		{
			cout << "invalid input" << endl;
			exit(1);
		}
	}
	
	if (maze.solve())				//try to solve
		maze.print();				//solve-print
	else
		cout << "no solution";		
			 
}