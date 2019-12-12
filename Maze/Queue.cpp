#include "Queue.h"


Queue::Queue()
{
	head = 1;
	tail = 0;
}


Queue::~Queue()
{
}

void Queue::MakeEmpty()
{
	head = 1;
	tail = 0;
}

bool Queue::isEmpty()
{
	return (AddOne(tail)==head);
}

char Queue::front()
{
	if (isEmpty())
	{
		cout << "Error: Queue IS EMPTY :(" << endl;
		exit(1);
	}
	return (data[head]);
	

}

void Queue::EnQueue(char item)
{
	if (AddOne(AddOne(tail)) == head)
	{
		cout << "Oh no!! Queue IS Full :(" << endl;
		exit(2);
	}
	tail = AddOne(tail);
	data[tail] = item;
}

char Queue::DeQueue()
{
	char item;

	if (isEmpty())
	{
		cout << "Error: Queue IS EMPTY :(" << endl;
		exit(3);
	}
	item = data[head];
	head = AddOne(head);
	return item;
}

int Queue::AddOne(int x)
{
	return ((1+x)%MAX_SIZE)
}

//

