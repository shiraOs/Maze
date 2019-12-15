#include "Maze.h"


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
		if (!shira.buildMaze())
			cout << "no solution" << endl;
		else
		{
			shira.solve();
			shira.print();
		}
	}
	else
		if (choice != 2)
			exit(5);
		else
		{
			shira.create();
			shira.solve();
			shira.print();
		}

	
	
	
}