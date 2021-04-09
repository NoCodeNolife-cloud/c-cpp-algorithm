#include "Assertion.h"
int main()
{
	Data<int> data_1;
	Data<int> data_2;
	Data<int> data_3;
	Queue<int> queue;

	data_1.SetDataValue();
	data_1.ShowDataValue();

	queue.Add(data_1);
	queue.Show();
	queue.ShowLength();

	data_2.SetDataValue();
	data_2.ShowDataValue();

	queue.Add(data_2);
	queue.ShowLength();
	queue.Show();

	queue.Out(data_3);
	data_3.ShowDataValue();
	queue.ShowLength();
	queue.Show();

	queue.Clean();
	queue.ShowLength();
	queue.Show();

	return 0;
}