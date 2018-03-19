 #include <iostream>
#include<string>

//logic constness and bitwise constness

using namespace std;

class BigArray{

	std::vector<int> v;
	mutable int accessCounter; //variable can be changed in the const function

public:
	int getItem(int index) const {

		accessCounter++;     //cannot make change to member variable
		return v[index];
	}
}