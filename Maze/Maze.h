#ifndef _MAZE_H
#define _MAZE_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
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

	int getHight();
	int getWidth();

	bool setHight(int hight);
	bool setWidth(int width);

	void create();
	void solve();

	void print();
};

#endif //_MAZE_H

