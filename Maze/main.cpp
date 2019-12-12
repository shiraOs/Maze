#include "Maze.h"


void main()
{
	Maze shira(9, 9);
	shira.print();
	cout << endl;
	shira.create();
	shira.print();
	system("pause");
}