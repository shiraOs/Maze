#include "Node.h"

Node::Node()
{
	next = nullptr;
}


Node::~Node()
{
}

Node::Node(int* data, Node* ptr)
{
	this->data[0] = data[0];
	this->data[1] = data[1];
	next = ptr;
}

void Node::InsertAfter(Node* newNode)
{
	newNode->next = next;
	next = newNode;
}

Node* Node::DeleteAfter()
{
	Node* temp = next;
	if (next == nullptr)
		return nullptr;
	next = temp->next;
	return temp;
}
