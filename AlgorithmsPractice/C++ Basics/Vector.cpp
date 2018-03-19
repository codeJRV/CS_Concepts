#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main()
{


	vector<int> vec;
	int i;


	//size of vector
	cout<<vec.size();

	//insert values into vector
	for(int i = 0 ; i < 5 ; i++)
	{

		vec.push_back(i);
	}

	//print using indexing
	for(int i = 0; i <5 ; i++)
	{
		cout<<"value "<<vec[i]<<endl;

	}

	vector<int>::iterator v = vec.begin();  //iterator is a pointer to the vector, hence we need to dereference it.
	while (v != vec.end()) {
		cout<<"value of V = "<< *v <<endl;
		v++;
	}

	return 0;

	

}