#include "Node.h"

Node::Node()
{
	next = nullptr;
}


Node::~Node()
{
}

Node::Node(char item, Node * ptr)
{
	data = item;
	next = ptr;
}

void Node::InsertAfter(Node * newNode)
{
	newNode->next = next;
	next = newNode;
}

Node * Node::DeleteAfter()
{
	Node* temp = next;
	if (next == nullptr)
		return nullptr;
	next = temp->next;
	return temp;
	return nullptr;
}
