#ifndef _QUEUE_H
#define _QUEUE_H

#include <iostream>
#include <stdlib.h>
using namespace std;

#pragma warning (disable: 4996)

const int MAX_SIZE = 2050;

class Queue
{

private:
	int head;
	int tail;
	char data[MAX_SIZE];

	static int AddOne(int x);


public:

	//ctor
	Queue();
	~Queue();

	void MakeEmpty();
	bool isEmpty();
	char front();
	void EnQueue(char item);
	char DeQueue();


};

#endif // !_QUEUE_H