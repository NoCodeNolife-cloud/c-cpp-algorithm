#pragma once
#include <iostream>
using namespace std;

//����
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

//����
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

//���캯��
template<typename T>
inline Data<T>::Data()
{
	dataValue = {};
	return;
}

//����ģ��ֵ
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

//����ģ��ֵ
template<typename T>
inline bool Data<T>::SetDataValue(T paraDataValue)
{
	dataValue = paraDataValue;
	return true;
}

//����ģ��ֵ
template<typename T>
inline T Data<T>::GetDataValue()
{
	return dataValue;
}

//��ʾģ��ֵ
template<typename T>
inline bool Data<T>::ShowDataValue()
{
	cout << "The data value is "
		<< dataValue
		<< endl;
	return true;
}

//���캯��
template<typename T>
inline Queue<T>::Queue()
{
	length = 0;
	return;
}

//�Ƿ�Ϊ��
template<typename T>
inline bool Queue<T>::IsEmpty()
{
	return length == 0;
}

//�Ƿ�Ϊ��
template<typename T>
inline bool Queue<T>::IsFull()
{
	return length == MAXLEN;
}

//��ʾ����
template<typename T>
inline bool Queue<T>::ShowLength()
{
	cout << "The length is "
		<< length
		<< endl;
	return true;
}

//���س���
template<typename T>
inline int Queue<T>::GetLength()
{
	return length;
}

//�������
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

//�����
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

//������
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

//��ʾ����
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
