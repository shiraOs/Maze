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

void Stack::Push(int* data)
{
	top = new Node(data, top);
}

int* Stack::Pop()
{
	if (IsEmpty())
	{
		cout << "Eror: STACK OVERFLOW!!!" << endl;
		exit(1);
	}
	
	Node* temp = top;
	int* item = new int[2];			//delete allocation in maze::create and after push-delete
	item[0] = top->data[0];
	item[1] = top->data[1];
	top = top->next;
	delete temp;
	return item;
}

int* Stack::Top()
{
	return top->data;
}
