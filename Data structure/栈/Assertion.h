#pragma once
class Stack
{
private:
	enum { MAX = 10 };
	unsigned long items[MAX];
	int top;
public:

	//���캯��
	Stack();

	//�ж��Ƿ�Ϊ��ջ
	bool isempty()const;

	//�ж��Ƿ�Ϊ��ջ
	bool isfull()const;

	//��ջ
	bool push(const unsigned long& item);

	//��ջ
	bool pop(unsigned long& item);

	//���ջ
	bool clear();
};
