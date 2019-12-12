#include "Maze.h"


void main()
{
	Maze shira(25, 25);
	shira.print();
	cout << endl;
	cout << endl;
	cout << endl;
	shira.create();
	shira.print();
	cout << endl;
	cout << endl;
	cout << endl;
	shira.solve();
	shira.print();
	system("pause");
}