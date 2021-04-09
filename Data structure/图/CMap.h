#pragma once
#include <iostream>
#include <vector>
using namespace std;

class CMap
{
private:
	int m_iCapacity;//图的节点的容量
	int m_iNodeCount;//图当前的节点的数量
	Node* m_pNodeArray;//指向图中首节点的指针
	int* m_pMatrix;//指向邻接矩阵首元素的指针

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
		delete[]m_pNodeArray;//想释放节点所对应的内存
		delete[]m_pMatrix;//再释放邻接矩阵所对应的内存
		return;
	}
	bool addNode(Node* pNode) {
		if (pNode == NULL) {//无法添加一个空节点
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
	//给无向表的邻接矩阵中row行，col列的元素设置值,默认是1
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
		m_pMatrix[row * m_iCapacity + col] = val;//将二维数组按行展开为一维数组
		m_pMatrix[col * m_iCapacity + row] = val;//将二维数组按列展开为一维数组
		return true;
	}
	bool getValueFromMatrix(int row, int col, int& val) //获取邻接矩阵对应位置处的元素值
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
	void printMartrix()                    //打印邻接矩阵中每个元素的值
	{
		for (int i = 0; i < m_iCapacity; i++)
		{
			for (int k = 0; k < m_iCapacity; k++)
			{
				cout << m_pMatrix[i * m_iCapacity + k] << " ";
			}
			cout << endl;                        //每打印m_iCapacity个元素换一行
		}
	}
	//深度优先遍历     用到了递归
	void depthFirstTraverse(int nodeIndex)        //既适用于无向图也适用于有向图
	{
		int value = 0;
		cout << m_pNodeArray[nodeIndex].m_cData << " "; //打印节点的数据域的值
		m_pNodeArray[nodeIndex].m_bIsVisited = true;    //将节点的访问状态置为访问了的状态

		for (int i = 0; i < m_iCapacity; i++)
		{
			getValueFromMatrix(nodeIndex, i, value);
			if (value != 0)            //表示nodeIndex这个索引的节点与索引为i的节点相连
			{
				if (m_pNodeArray[i].m_bIsVisited)//已经访问过的话就避免重复访问
				{
					continue;
				}
				else
				{
					depthFirstTraverse(i);      //使用到了递归
				}
			}
			else
			{
				continue;
			}
		}
	}
	//广度优先遍历    这个遍历的算法实现起来最为麻烦，要使用到下面的函数breadthFirstTraverseImpl(vector<int> preVec)
	void breadthFirstTraverse(int nodeIndex)
	{
		cout << m_pNodeArray[nodeIndex].m_cData << " ";
		m_pNodeArray[nodeIndex].m_bIsVisited = true;
		vector<int> curVec;
		curVec.push_back(nodeIndex);
		breadthFirstTraverseImpl(curVec);
	}
	void breadthFirstTraverseImpl(vector<int> preVec)//vector类其实就是一个封装的数组
	{
		int value = 0;
		vector<int> curVec;
		for (int j = 0; j < (int)preVec.size(); j++)
		{
			for (int i = 0; i < m_iCapacity; i++)
			{
				getValueFromMatrix(preVec[j], i, value);//查看上一层节点与当前层节点是否有连接的
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

						curVec.push_back(i);                  //把这一层存入curVec数组中
					}
				}
			}
		}
		if (curVec.size() == 0)             //如果该层没有点，则直接返回函数调用处，且什么都不做
		{
			return;
		}
		else                              //若该层有点，则递归执行当前的遍历操作
		{
			breadthFirstTraverseImpl(curVec);
		}
	}
};