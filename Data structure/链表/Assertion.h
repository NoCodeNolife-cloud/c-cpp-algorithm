#pragma once
#include <iostream>
template <typename T>
class Node
{
public:
	Node<T>* next;
	Node<T>* prev;
	T data;
};

template <class T>
class List
{
public:

	/// @brief Ĭ�Ϲ��캯��
	List();

	/// @brief �������캯��
	/// @param ln
	List(const List& ln);
	~List();

	/// @brief �������������
	/// @param e
	void add(T e);

	/// @brief ��������
	void ascSort();

	/// @brief �Ƴ�ĳ�����
	/// @param index
	void remove(T index);

	/// @brief ���ҽ��
	/// @param index
	/// @return
	T find(int index);

	/// @brief �ж��Ƿ�Ϊ��
	/// @return
	bool isEmpty();

	/// @brief ������
	/// @return
	int size();

	/// @brief ��ʾ����
	void show();

	/// @brief ��������ʾ
	void resShow();

	/// @brief ɾ��ȫ�����
	void removeAll();
private:

	/// @brief ͷָ��
	Node<T>* head;

	/// @brief βָ��
	Node<T>* tail;

	/// @brief ����
	int length;
};

//Ĭ�Ϲ��캯��
template <typename T>
List<T>::List()
{
	/// @brief head��tail������������
	head = new Node<T>;
	tail = new Node<T>;
	head->next = tail;
	head->prev = nullptr;
	tail->next = nullptr;
	tail->prev = head;
	length = 0;
}

//�������캯��
template <typename T>
List<T>::List(const List& ln)
{
	/// @brief ��ʼ��
	head = new Node<T>;
	head->prev = nullptr;
	tail = new Node<T>;
	head->next = tail;
	tail->prev = head;
	length = 0;

	/// @brief ����
	Node<T>* temp = ln.head;
	while (temp->next != ln.tail)
	{
		temp = temp->next;
		tail->data = temp->data;

		/// @brief Ϊ��һ�������ڴ�
		Node<T>* p = new Node<T>;
		p->prev = tail;
		tail->next = p;

		/// @brief β��ָ������
		tail = p;
		length++;
	}
	tail->next = nullptr;
}

//�������������
template <typename T>
void List<T>::add(T e)
{
	Node<T>* temp = this->tail;
	tail->data = e;

	/// @brief �����ڴ�
	tail->next = new Node<T>;
	Node<T>* p = tail;
	tail = tail->next;
	tail->prev = p;
	tail->next = nullptr;
	length++;
}

//���ҽ��
template <typename T>
T List<T>::find(int index)
{
	/// @brief �п�
	if (length == 0)
	{
		std::cout << "List is empty";
		return NULL;
	}

	/// @brief �����
	if (index >= length)
	{
		std::cout << "Out of bounds";
		return NULL;
	}
	int x = 0;
	T data;
	Node<T>* p;

	/// @brief �������ײ���β������
	if (index < length / 2)
	{
		p = head->next;
		while (p->next != nullptr && x++ != index)
		{
			p = p->next;
		}
	}

	/// @brief ������β�����ײ�����
	else {
		p = tail->prev;
		while (p->prev != nullptr && x++ != index)
		{
			p = p->prev;
		}
	}
	return p->data;
}

//ɾ�����
template <typename T>
void List<T>::remove(T index)
{
	if (length == 0)
	{
		std::cout << "List is empty";
		return;
	}
	Node<T>* p = head;
	while (p->next != nullptr)
	{
		p = p->next;
		if (p->data == index)
		{
			Node<T>* temp = p->prev;
			temp->next = p->next;
			p->next->prev = temp;

			/// @brief �ͷ��ڴ�
			delete p;
			length--;
			return;
		}
	}
}

//ɾ�����н��
template <typename T>
void List<T>::removeAll()
{
	if (length == 0)
	{
		return;
	}

	/// @brief �ͷ��ڴ�
	Node<T>* p = head->next;
	while (p != tail)
	{
		Node<T>* temp = p;
		p = p->next;
		delete temp;
	}
	head->next = tail;
	tail->prev = head;
	length = 0;
}

//ѡ�������㷨
template <typename T>
void List<T>::ascSort()
{
	if (length <= 1) return;
	Node<T>* p = head->next;
	for (int i = 0; i < length - 1; i++)
	{
		Node<T>* q = p->next;
		for (int j = i + 1; j < length; j++)
		{
			if (p->data > q->data)
			{
				T temp = q->data;
				q->data = p->data;
				p->data = temp;
			}
			q = q->next;
		}
		p = p->next;
	}
}

//�ж��Ƿ�Ϊ��
template <typename T>
bool List<T>::isEmpty()
{
	if (length == 0)
	{
		return true;
	}
	else {
		return false;
	}
}

//������
template <typename T>
int List<T>::size()
{
	return length;
}

//�������
template <typename T>
void List<T>::show()
{
	if (length == 0)
	{
		std::cout << "List is empty" << std::endl;
		return;
	}
	Node<T>* p = head->next;
	while (p != tail)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << std::endl;
}

//�����������
template <typename T>
void List<T>::resShow()
{
	if (length == 0)return;
	Node<T>* p = tail->prev;
	while (p != head)
	{
		std::cout << p->data << " ";
		p = p->prev;
	}
	std::cout << std::endl;
}

//��������
template <typename T>
List<T>::~List()
{
	if (length == 0)
	{
		delete head;
		delete tail;
		head = nullptr;
		tail = nullptr;
		return;
	}
	while (head->next != nullptr)
	{
		Node<T>* temp = head;
		head = head->next;
		delete temp;
	}
	delete head;
	head = nullptr;
}
