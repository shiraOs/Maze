#ifndef _MAZE_H
#define _MAZE_H

#include <iostream>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"



using namespace std;

#pragma warning (disable: 4996)

class Maze
{
private:
	char **maze;
	int hight;
	int width;

public:
	Maze(int hight,int width);
	~Maze();

	bool setHight(int hight);
	bool setWidth(int width);

	void print();
};

#endif //_MAZE_H

