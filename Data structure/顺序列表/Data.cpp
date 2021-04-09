#include "Declaration.h"

Data::Data()
{
	return;
}

void Data::EnterData()
{
	cout << "输入关键字:";
	cin >> key;
	cout << "输入结点信息:";
	cin >> information;
	return;
}

int Data::DataGetInformation()
{
	return information;
}

string Data::DataGetKey() {
	return key;
}