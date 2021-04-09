#pragma once
class Stack
{
private:
	enum { MAX = 10 };
	unsigned long items[MAX];
	int top;
public:

	//构造函数
	Stack();

	//判断是否为空栈
	bool isempty()const;

	//判断是否为满栈
	bool isfull()const;

	//入栈
	bool push(const unsigned long& item);

	//出栈
	bool pop(unsigned long& item);

	//清空栈
	bool clear();
};
