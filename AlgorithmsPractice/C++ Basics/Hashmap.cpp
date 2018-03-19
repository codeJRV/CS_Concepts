#include <iostream>
#include<iterator>
#include<map>

using namespace std;

int main()
{
	map<int, int> mymap;

	mymap.insert(pair<int,int> (1,20));
	mymap.insert(pair<int,int> (2,24));
	mymap.insert(pair<int,int> (3,60));
	mymap.insert(pair<int,int> (4,40));
	mymap.insert(pair<int,int> (2,30));  //wont be inserted
	mymap.insert(pair<int,int> (6,20));

	map <int,int> ::iterator itr;
	cout<<"Map is \n";
	for (itr = mymap.begin(); itr != mymap.end(); ++itr)
	{
		cout<<"Key : "<<itr->first<<" value : "<< itr-> second<<"\n";

	}cout<<endl;

	//access element

	cout<<"Second: "<<mymap.find(2)->second<<"\n";
	cout<<"First: "<<mymap.find(2)->first<<"\n";




}