#include "Maze.h"


//Maze Creator and Solver 
//by Alon Ben Harosh 
///Shira kflsahfuetop XXXXXXXXXX <====== shira enter here
//Choose 1 to enter your own maze by and 2 for the Random Creation of a maze
//after that enter your higth(3-20) and width(3-80) of the maze: an un-even number
//if your choose 1: enter the stirngs of char wish only '*' or 'space' 
//the perimeter most be only * and an opening point at 1,0 and h-2,w-1
//enjoy!!
int main()
{
	
	int choice, h, w;
	Maze *maze;
	cout << "Maze: 1) From input 2) Random" << endl;
	cin >> choice>>h>>w;
	cout<< endl;
	
	maze = new Maze(h, w);


	if (choice == 1)
	{
		if (!maze->buildMaze())
		{
			cout << "invalid input" << endl;
			exit(1);
		}
		else
		{
			if (maze->solve())
				maze->print();
			else
				cout << "no solution";
		}
	}
	else
		if (choice != 2)
			exit(5);
		else
		{
			maze->create();
			if (maze->solve())
				maze->print();
			else
				cout << "no solution"; //:)
		}
	delete maze;
}