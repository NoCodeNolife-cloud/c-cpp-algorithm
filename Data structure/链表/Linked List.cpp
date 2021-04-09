#include "Assertion.h"
int main()
{
	List<float> ls1;
	ls1.add(1.1);
	ls1.add(0.1);
	ls1.add(6);
	ls1.add(3.3);
	List<float> ls2(ls1);
	ls2.resShow();
	std::cout << ls2.size() << std::endl;
	std::cout << ls2.find(00) << std::endl;
	ls2.remove(6);
	ls1.resShow();
	ls2.show();
	system("pause");
	return 0;
}