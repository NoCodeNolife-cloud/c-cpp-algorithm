#pragma once
#include <vector>

class Number {
private:

	std::vector<int>vec;

public:

	Number ( std::vector<int> vec ) {

		this->vec = vec;
	}

	std::vector<int> getNextPermutation () {

		int left = vec.size () - 2;
		while ( left >= 0 && vec [ left ] >= vec [ left + 1 ] ) {
			--left;
		}

		if ( left >= 0 ) {
			int right = vec.size () - 1;
			while ( vec [ left ] > vec [ right ] ) {
				--right;
			}
			std::swap ( vec [ left ] , vec [ right ] );
		}

		std::reverse ( vec.begin () + left + 1 , vec.end () );

		return vec;
	}
};
