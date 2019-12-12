#ifndef _STACK_H
#define _STACK_H

#include <iostream>
#include <stdlib.h>
#include "Node.h"

using namespace std;

#pragma warning (disable: 4996)

class Stack
{
private:
	Node* top;

public:
	Stack();
	~Stack();
	void MakeEmpty();
	bool IsEmpty();
	void Push(char item);
	char Pop();
	char Top();
};

#endif //_STACK_H