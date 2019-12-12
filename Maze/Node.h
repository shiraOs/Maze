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
	char data;
	Node* next;
	Node(char item, Node* ptr = nullptr);
	void InsertAfter(Node* newNode);
	Node* DeleteAfter();
};

#endif //_NODE_H

