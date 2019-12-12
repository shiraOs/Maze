#include "Maze.h"


void main()
{
	int choice, h, w;
	cout << "What do you want? \n 1. Build your own maze \n 2. Costumase maze\n";
	cin >> choice;
	cout << "Enter maze's hight: ";
	cin >> h;
	cout << "\nEnter maze's width: ";
	cin >> w;
	cout << endl;
	Maze shira(h, w);

	if (choice == 1)
		shira.buildMaze();
	else if (choice != 2)
		exit(5);

	shira.print();
	system("pause");
}