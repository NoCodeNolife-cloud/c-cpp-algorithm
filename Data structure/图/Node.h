#pragma once
class Node
{
public:
	char m_cData;//����������
	bool m_bIsVisited;//��Ǹýڵ��Ƿ񱻷��ʹ�(״̬)
	Node(char data = 0) {//�ڵ�Ĺ��캯��
		m_cData = data;
		m_bIsVisited = false;//Ĭ��δ���ʹ�
		return;
	}
};
