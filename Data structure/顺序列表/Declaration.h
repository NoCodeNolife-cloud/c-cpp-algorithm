#pragma once
#include <string>
#include <iostream>
#define MAXLEN 100

using namespace std;

class Data//�洢��Ԫ
{
protected:
	int information;//�����Ϣ
	string key;//���ؼ���
public:
	Data();

	//����ֵ
	void EnterData();

	//��ȡ��Ϣ
	int DataGetInformation();

	//��ȡ�ؼ���
	string DataGetKey();
};

class SLType
{
protected:
	Data ListData[MAXLEN + 1];
	int ListLen;//˳�����
public:

	//��ʼ��˳���
	SLType();

	//����˳�����
	int SLLength();

	//������
	int SLInsert(int para_n, Data para_data);

	//׷�ӽ��
	int SLAdd(Data data);

	//ɾ�����
	int SLDelete(int para_n);

	//������Ų��ҽ��
	Data* SLfindByNum(int para_n);

	//���չؼ��ֲ��ҽ��
	int SLFindByCont(string para_key);

	//��ʾ���н��
	int SLAll();
};
