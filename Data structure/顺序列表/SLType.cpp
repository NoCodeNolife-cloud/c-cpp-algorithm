#include "Declaration.h"

SLType::SLType() {
	ListLen = 0;//设置长度为0
}

int SLType::SLLength()
{
	return ListLen;//长度
}

int SLType::SLInsert(int para_n, Data para_data)
{
	using namespace std;
	if (ListLen >= MAXLEN) {
		cout << "顺序表已满,不能插入结点!"
			<< endl;
		return 0;
	}
	if (para_n<1 || para_n>ListLen - 1) {
		cout << "插入元素序号错误,不能插入结点!"
			<< endl;
		return 0;
	}
	for (int i = ListLen; i >= para_n; i--) {
		ListData[i + 1] = ListData[i];
	}//移动数据
	ListData[para_n] = para_data;
	ListLen++;//长度加一
	return 1;
}

int SLType::SLAdd(Data para_data)
{
	using namespace std;
	if (ListLen >= MAXLEN) {
		cout << "顺序表已满,不能添加结点!"
			<< endl;
		return 0;
	}
	ListData[ListLen] = para_data;//填入顺序表
	ListLen++;//长度加一
	return 1;
}

int SLType::SLDelete(int para_n)
{
	using namespace std;
	if (para_n<1 || para_n>ListLen) {
		cout << "删除结点序号错误,不能删除结点!"
			<< endl;
		return 1;
	}
	for (int i = para_n; i < ListLen; i++) {
		ListData[i] = ListData[i + 1];
	}
	ListLen--;//长度减一
	return 1;
}

Data* SLType::SLfindByNum(int para_n)
{
	using namespace std;
	if (para_n<1 || para_n>ListLen + 1) {
		cout << "结点数据错误,不能返回结点!"
			<< endl;
		return NULL;//返回NULL,针对于指针
	}
	return&(ListData[para_n]);//pr <-> &r
}

int SLType::SLFindByCont(string para_key)
{
	for (int i = 1; i < ListLen; i++) {
		if (ListData[i].DataGetKey() == para_key) {
			return i;
		}//查找关键字
	}//遍历
	cout << "没有找到!"
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
	}//遍历显示
	return 0;
}