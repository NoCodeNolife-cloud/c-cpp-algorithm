#pragma once

template<class T>
class DNode
{
private:
	DNode<T>* left;
	DNode<T>* right;
public:
	T data;//�������
	DNode(void) {
		left = right = this;//��ʼ�����,ʹָ֮������
	}
	DNode(const T& item) {//���캯��,����һ���ս�㲢��ʼ�����ݳ�Ա
		left = right = this;//ʹ���ָ��ָ��������ʼ�����ݳ�Ա
		data = item;
		return;
	}
	void insertRight(DNode<T>* p) {//�ڵ�ǰ�����Ҳ����һ�����
		//��p���ҽڵ�����
		p->right = right;
		right->left = p;
		//����ǰ������ӵ�p�������
		p->left = this;
		right = p;
		return;
	}
	void insertLeft(DNode<T>* p) {
		//��p����ڵ�����
		p->left = left;
		left->right = p;
		//�����ڽ�����ӵ�p�����Ҳ�
		p->right = this;
		left = p;
		return;
	}
	DNode<T>* deleteNode(void) {//�Ͽ���ǰ��������������,�����ص�ǰ����ַ
		left->right = right;//ʹ��ǰ������������ӵ���ǰ�����������
		right->left = left;//ʹ��ǰ�����Ҳ������ӵ���ǰ���������
		return this;//���ص�ǰ����ַ
	}
	DNode<T>* nextNodeRight(void)const { return right; }
	DNode<T>* nextNodeLeft(void)const { return left; }
};
