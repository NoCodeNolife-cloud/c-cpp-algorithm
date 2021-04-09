#pragma once
class Node
{
public:
	char m_cData;//结点的数据域
	bool m_bIsVisited;//标记该节点是否被访问过(状态)
	Node(char data = 0) {//节点的构造函数
		m_cData = data;
		m_bIsVisited = false;//默认未访问过
		return;
	}
};
