#pragma once
#include <string>
#include <iostream>
#define MAXLEN 100

using namespace std;

class Data//存储单元
{
protected:
	int information;//结点信息
	string key;//结点关键字
public:
	Data();

	//输入值
	void EnterData();

	//获取信息
	int DataGetInformation();

	//获取关键字
	string DataGetKey();
};

class SLType
{
protected:
	Data ListData[MAXLEN + 1];
	int ListLen;//顺序表长度
public:

	//初始化顺序表
	SLType();

	//计算顺序表长度
	int SLLength();

	//插入结点
	int SLInsert(int para_n, Data para_data);

	//追加结点
	int SLAdd(Data data);

	//删除结点
	int SLDelete(int para_n);

	//按照序号查找结点
	Data* SLfindByNum(int para_n);

	//按照关键字查找结点
	int SLFindByCont(string para_key);

	//显示所有结点
	int SLAll();
};
