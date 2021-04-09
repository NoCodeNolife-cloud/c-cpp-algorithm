#include "assertion.h"

Stack::Stack()
{
	top = 0;
	for (int i = 0; i < MAX; i++) {
		items[i] = 0;
	}
}

bool Stack::isempty() const
{
	return top == 0;
}

bool Stack::isfull() const
{
	return top == MAX;
}

bool Stack::push(const unsigned long& item)
{
	if (top < MAX) {
		items[top++] = item;
		return true;
	}
	else {
		return false;
	}
}

bool Stack::pop(unsigned long& item)
{
	if (top > 0) {
		item = items[--top];
		return true;
	}
	else {
		return false;
	}
}

bool Stack::clear()
{
	top = 0;
	return true;
}