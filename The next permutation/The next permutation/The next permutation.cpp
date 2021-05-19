#include <iostream>
#include <vector>
#include "Number.h"

int main () {
	std::vector<int> vec = { 4,5,6,1,2,3 };

	Number number ( vec );

	vec = number.getNextPermutation ();
	for ( int item : vec ) {

		std::cout << item << " ";
	}
	std::cout << std::endl;

	system ( "pause" );
}