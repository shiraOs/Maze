#include "Maze.h"

//Maze Creator and Solver
//by Alon Ben Harosh
//Shira ostrinsky 311119002
//Choose 1 to enter your own maze by and 2 for the Random Creation of a maze
//after that enter your higth(3-20) and width(3-80) of the maze: an un-even number
//if your choose 1: enter the string of chars with only: '*' for wall, or 'space' for blank
//the perimeter most be only * and an opening point at 1,0 and h-2,w-1
//enjoy!
int main()
{

	int choice, h, w;


	cout << "Maze: 1) From input 2) Random" << endl;

	cin >> choice;

	cin >> h;

	cin >> w;
	cout << endl;

	Maze shira(h, w);


	if (choice == 1)
	{
		if (shira.buildMaze() == false)
			cout << "invalid input" << endl;
		else
		{
			if (shira.solve())
				shira.print();
			else
				cout << "no solution";
		}
	}
	else
		if (choice != 2)
			exit(5);
		else
		{
			shira.create();
			if (shira.solve())
				shira.print();
			else
				cout << "no solution"; //:)
		}
	   	 
}