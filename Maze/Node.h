#ifndef _NODE_H
#define _NODE_H

#include <iostream>
#include <stdlib.h>
using namespace std;

#pragma warning (disable: 4996)

class Node
{
public:
	Node();
	~Node();
	int data[2]; // data[0]=row, data[1]=col :)
	Node* next;
	Node(int* data, Node* ptr = nullptr);
	void InsertAfter(Node* newNode);
	Node* DeleteAfter();
};

#endif //_NODE_H

