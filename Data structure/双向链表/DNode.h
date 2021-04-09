#pragma once

template<class T>
class DNode
{
private:
	DNode<T>* left;
	DNode<T>* right;
public:
	T data;//结点数据
	DNode(void) {
		left = right = this;//初始化结点,使之指向自身
	}
	DNode(const T& item) {//构造函数,创建一个空结点并初始化数据成员
		left = right = this;//使结点指针指向自身并初始化数据成员
		data = item;
		return;
	}
	void insertRight(DNode<T>* p) {//在当前结点的右侧插入一个结点
		//将p与右节点连接
		p->right = right;
		right->left = p;
		//将当前结点连接到p结点的左侧
		p->left = this;
		right = p;
		return;
	}
	void insertLeft(DNode<T>* p) {
		//将p与左节点连接
		p->left = left;
		left->right = p;
		//将当期结点连接到p结点的右侧
		p->right = this;
		left = p;
		return;
	}
	DNode<T>* deleteNode(void) {//断开当前结点与链表的连接,并返回当前结点地址
		left->right = right;//使当前结点的左侧结点连接到当前啦结点的左侧结点
		right->left = left;//使当前结点的右侧结点连接到当前结点的左侧结点
		return this;//返回当前结点地址
	}
	DNode<T>* nextNodeRight(void)const { return right; }
	DNode<T>* nextNodeLeft(void)const { return left; }
};
