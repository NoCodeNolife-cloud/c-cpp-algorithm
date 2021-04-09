#include "Declaration.h"

SLType::SLType() {
	ListLen = 0;//���ó���Ϊ0
}

int SLType::SLLength()
{
	return ListLen;//����
}

int SLType::SLInsert(int para_n, Data para_data)
{
	using namespace std;
	if (ListLen >= MAXLEN) {
		cout << "˳�������,���ܲ�����!"
			<< endl;
		return 0;
	}
	if (para_n<1 || para_n>ListLen - 1) {
		cout << "����Ԫ����Ŵ���,���ܲ�����!"
			<< endl;
		return 0;
	}
	for (int i = ListLen; i >= para_n; i--) {
		ListData[i + 1] = ListData[i];
	}//�ƶ�����
	ListData[para_n] = para_data;
	ListLen++;//���ȼ�һ
	return 1;
}

int SLType::SLAdd(Data para_data)
{
	using namespace std;
	if (ListLen >= MAXLEN) {
		cout << "˳�������,������ӽ��!"
			<< endl;
		return 0;
	}
	ListData[ListLen] = para_data;//����˳���
	ListLen++;//���ȼ�һ
	return 1;
}

int SLType::SLDelete(int para_n)
{
	using namespace std;
	if (para_n<1 || para_n>ListLen) {
		cout << "ɾ�������Ŵ���,����ɾ�����!"
			<< endl;
		return 1;
	}
	for (int i = para_n; i < ListLen; i++) {
		ListData[i] = ListData[i + 1];
	}
	ListLen--;//���ȼ�һ
	return 1;
}

Data* SLType::SLfindByNum(int para_n)
{
	using namespace std;
	if (para_n<1 || para_n>ListLen + 1) {
		cout << "������ݴ���,���ܷ��ؽ��!"
			<< endl;
		return NULL;//����NULL,�����ָ��
	}
	return&(ListData[para_n]);//pr <-> &r
}

int SLType::SLFindByCont(string para_key)
{
	for (int i = 1; i < ListLen; i++) {
		if (ListData[i].DataGetKey() == para_key) {
			return i;
		}//���ҹؼ���
	}//����
	cout << "û���ҵ�!"
		<< endl;
	return 0;
}

int SLType::SLAll()
{
	for (int i = 0; i < ListLen; i++) {
		cout << ListData[i].DataGetKey()
			<< "\t"
			<< ListData[i].DataGetInformation()
			<< endl;
	}//������ʾ
	return 0;
}