#include "Declaration.h"

Data::Data()
{
	return;
}

void Data::EnterData()
{
	cout << "����ؼ���:";
	cin >> key;
	cout << "��������Ϣ:";
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