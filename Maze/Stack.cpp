#include "Stack.h"

Stack::Stack()
{
	top = nullptr;
}

Stack::~Stack()
{
	MakeEmpty();
}

void Stack::MakeEmpty()
{
	Node* temp;
	while (top != nullptr)
	{
		temp = top;
		top = top->next;
		delete temp;
	}
}

bool Stack::IsEmpty()
{
	return (top == nullptr);
}

void Stack::Push(char item)
{
	top = new Node(item, top);
}

char Stack::Pop()
{
	if (IsEmpty())
	{
		cout << "Eror: STACK OVERFLOW!!!" << endl;
		exit(4);
	}
	Node* temp = top;
	char item = top->data;
	top = top->next;
	delete temp;
	return item;
}

char Stack::Top()
{
	return top->data;
}
