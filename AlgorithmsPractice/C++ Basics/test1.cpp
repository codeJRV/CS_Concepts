#include<iostream>
#include<sting>
using namespace std;

//const used with functions

class Foo{

	int age;
	string name;

public:
	Foo(){age = 3; name = "dummy" ; }
	void setAge(const int& a){ age = a;}     //const reference used to ensure that the value cannot be changed by the function
	void setAge(const int a){ age = a;}		 //using this is useless from the callers point of view

	//const return value
	cont string& getName() {return name;}

	//const function  : cannot change the member values of this class.
	void printFooName() const {  cout << getName() << "const "<<endl;  } //will be invoked when the class object is a const
	void printFooName()  {  cout << getName() << "const "<<endl;  }  // will be invoked when the class object is not a const





};


int main()
{
	const int i = 9;
	const int *p1 = &i;

	int* const p2;  		//pointer is const, data is not
	const int* const p3; 
 
 	//  if const is on the left of a *, data  = constant
 	//	if const is on the right of a * pointer = constant

	const_cast<int&>(i) = 6;   // this is how you change value of a constant

	int j;
	static_cast<cont int&>(j) = 7;  //this is how you change a variable to constant if needed

	Foo d;

	// const using functions  
	cont string& n = d.getName();
	cout<<n<<endl; 


}


