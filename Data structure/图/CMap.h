#pragma once
#include <iostream>
#include <vector>
using namespace std;

class CMap
{
private:
	int m_iCapacity;//ͼ�Ľڵ������
	int m_iNodeCount;//ͼ��ǰ�Ľڵ������
	Node* m_pNodeArray;//ָ��ͼ���׽ڵ��ָ��
	int* m_pMatrix;//ָ���ڽӾ�����Ԫ�ص�ָ��

public:
	CMap(int capacity) {
		m_iCapacity = capacity;
		m_iNodeCount = 0;
		m_pNodeArray = new Node[m_iCapacity];
		m_pMatrix = new int[m_iCapacity * m_iCapacity];
		for (int i = 0; i < m_iCapacity * m_iCapacity; i++) {
			m_pMatrix[i] = 0;
		}
		return;
	}
	~CMap(void) {
		delete[]m_pNodeArray;//���ͷŽڵ�����Ӧ���ڴ�
		delete[]m_pMatrix;//���ͷ��ڽӾ�������Ӧ���ڴ�
		return;
	}
	bool addNode(Node* pNode) {
		if (pNode == NULL) {//�޷����һ���սڵ�
			return false;
		}
		m_pNodeArray[m_iNodeCount] = pNode->m_cData;
		m_iNodeCount++;
		return true;
	}
	void resetNode()
	{
		for (int i = 0; i < m_iNodeCount; i++)
		{
			m_pNodeArray[i].m_bIsVisited = false;
		}
	}
	//���������ڽӾ�����row�У�col�е�Ԫ������ֵ,Ĭ����1
	bool setValueToMatrixForUndirectedGraph(int row, int col, int val)
	{
		if (row < 0 || row >= m_iCapacity)
		{
			return false;
		}
		if (col < 0 || col >= m_iCapacity)
		{
			return false;
		}
		m_pMatrix[row * m_iCapacity + col] = val;//����ά���鰴��չ��Ϊһά����
		m_pMatrix[col * m_iCapacity + row] = val;//����ά���鰴��չ��Ϊһά����
		return true;
	}
	bool getValueFromMatrix(int row, int col, int& val) //��ȡ�ڽӾ����Ӧλ�ô���Ԫ��ֵ
	{
		if (row < 0 || row >= m_iCapacity)
		{
			return false;
		}
		if (col < 0 || col >= m_iCapacity)
		{
			return false;
		}
		val = m_pMatrix[row * m_iCapacity + col];
		return true;
	}
	void printMartrix()                    //��ӡ�ڽӾ�����ÿ��Ԫ�ص�ֵ
	{
		for (int i = 0; i < m_iCapacity; i++)
		{
			for (int k = 0; k < m_iCapacity; k++)
			{
				cout << m_pMatrix[i * m_iCapacity + k] << " ";
			}
			cout << endl;                        //ÿ��ӡm_iCapacity��Ԫ�ػ�һ��
		}
	}
	//������ȱ���     �õ��˵ݹ�
	void depthFirstTraverse(int nodeIndex)        //������������ͼҲ����������ͼ
	{
		int value = 0;
		cout << m_pNodeArray[nodeIndex].m_cData << " "; //��ӡ�ڵ���������ֵ
		m_pNodeArray[nodeIndex].m_bIsVisited = true;    //���ڵ�ķ���״̬��Ϊ�����˵�״̬

		for (int i = 0; i < m_iCapacity; i++)
		{
			getValueFromMatrix(nodeIndex, i, value);
			if (value != 0)            //��ʾnodeIndex��������Ľڵ�������Ϊi�Ľڵ�����
			{
				if (m_pNodeArray[i].m_bIsVisited)//�Ѿ����ʹ��Ļ��ͱ����ظ�����
				{
					continue;
				}
				else
				{
					depthFirstTraverse(i);      //ʹ�õ��˵ݹ�
				}
			}
			else
			{
				continue;
			}
		}
	}
	//������ȱ���    ����������㷨ʵ��������Ϊ�鷳��Ҫʹ�õ�����ĺ���breadthFirstTraverseImpl(vector<int> preVec)
	void breadthFirstTraverse(int nodeIndex)
	{
		cout << m_pNodeArray[nodeIndex].m_cData << " ";
		m_pNodeArray[nodeIndex].m_bIsVisited = true;
		vector<int> curVec;
		curVec.push_back(nodeIndex);
		breadthFirstTraverseImpl(curVec);
	}
	void breadthFirstTraverseImpl(vector<int> preVec)//vector����ʵ����һ����װ������
	{
		int value = 0;
		vector<int> curVec;
		for (int j = 0; j < (int)preVec.size(); j++)
		{
			for (int i = 0; i < m_iCapacity; i++)
			{
				getValueFromMatrix(preVec[j], i, value);//�鿴��һ��ڵ��뵱ǰ��ڵ��Ƿ������ӵ�
				if (value != 0)
				{
					if (m_pNodeArray[i].m_bIsVisited)
					{
						continue;
					}
					else
					{
						cout << m_pNodeArray[i].m_cData << " ";
						m_pNodeArray[i].m_bIsVisited = true;

						curVec.push_back(i);                  //����һ�����curVec������
					}
				}
			}
		}
		if (curVec.size() == 0)             //����ò�û�е㣬��ֱ�ӷ��غ������ô�����ʲô������
		{
			return;
		}
		else                              //���ò��е㣬��ݹ�ִ�е�ǰ�ı�������
		{
			breadthFirstTraverseImpl(curVec);
		}
	}
};