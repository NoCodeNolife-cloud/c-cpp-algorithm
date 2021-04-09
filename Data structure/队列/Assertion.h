#pragma once
#include <iostream>
using namespace std;

//数据
template<typename T>
class Data
{
protected:
	T dataValue;
public:
	Data();
	bool SetDataValue();
	bool SetDataValue(T paraDataValue);
	T GetDataValue();
	bool ShowDataValue();
};

//队列
template<typename T>
class Queue
{
protected:
	enum { MAXLEN = 15 };
	Data<T> queueData[MAXLEN];
	int length;
public:
	Queue();
	bool IsEmpty();
	bool IsFull();
	bool ShowLength();
	int GetLength();
	bool Clean();
	bool Add(Data<T>paraData);
	bool Out(Data<T>& paraData);
	bool Show();
};

//构造函数
template<typename T>
inline Data<T>::Data()
{
	dataValue = {};
	return;
}

//设置模板值
template<typename T>
inline bool Data<T>::SetDataValue()
{
	cout << "Set value operation, Enter the value:";
	if (cin >> dataValue) {
		return true;
	}
	else {
		cout << "You enter the error value!"
			<< endl;
		cin.clear();
		cin.ignore();
		SetDataValue();
		return false;
	}
}

//设置模板值
template<typename T>
inline bool Data<T>::SetDataValue(T paraDataValue)
{
	dataValue = paraDataValue;
	return true;
}

//返回模板值
template<typename T>
inline T Data<T>::GetDataValue()
{
	return dataValue;
}

//显示模板值
template<typename T>
inline bool Data<T>::ShowDataValue()
{
	cout << "The data value is "
		<< dataValue
		<< endl;
	return true;
}

//构造函数
template<typename T>
inline Queue<T>::Queue()
{
	length = 0;
	return;
}

//是否为空
template<typename T>
inline bool Queue<T>::IsEmpty()
{
	return length == 0;
}

//是否为满
template<typename T>
inline bool Queue<T>::IsFull()
{
	return length == MAXLEN;
}

//显示长度
template<typename T>
inline bool Queue<T>::ShowLength()
{
	cout << "The length is "
		<< length
		<< endl;
	return true;
}

//返回长度
template<typename T>
inline int Queue<T>::GetLength()
{
	return length;
}

//清除队列
template<typename T>
inline bool Queue<T>::Clean()
{
	cout << "Clean operation"
		<< endl;
	length = 0;
	cout << "Done!"
		<< endl;
	return true;
}

//入队列
template<typename T>
inline bool Queue<T>::Add(Data<T> paraData)
{
	if (IsFull()) {
		cout << "The queue is full"
			<< endl;
		return false;
	}
	queueData[length] = paraData;
	length++;
	return true;
}

//出队列
template<typename T>
inline bool Queue<T>::Out(Data<T>& paraData)
{
	if (IsEmpty()) {
		cout << "The equeue is empty"
			<< endl;
		return false;
	}
	paraData.SetDataValue(queueData[0].GetDataValue());
	length--;
	if (IsEmpty()) {
		return true;
	}
	for (int i = 0; i < length; i++) {
		queueData[i] = queueData[i + 1];
	}
	return true;
}

//显示队列
template<typename T>
inline bool Queue<T>::Show()
{
	if (IsEmpty()) {
		cout << "The elements of the queue are none"
			<< endl;
		return true;
	}
	cout << "The elements of the queue are as follows:"
		<< endl;
	for (int i = 0; i < length; i++) {
		cout << "#"
			<< i + 1
			<< "\t"
			<< queueData[i].GetDataValue()
			<< endl;
	}
	return true;
}
