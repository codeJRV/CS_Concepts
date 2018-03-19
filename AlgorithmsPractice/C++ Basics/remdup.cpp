#include <iostream>
#include<vector>
#include <iterator>
#include<unordered_map>



using namespace std;

int main()
{

vector <int> v ;
int val;
int n;
cin>>n;
cout<<"Enter values"<<endl;

for(int i = 0; i <n ; ++i)
{
	cin>>val;
	v.push_back(val);

}


 unordered_map <int,int> umap;

vector <int>::iterator it;
int count = 0;

for ( int i = 0; i< v.size(); ++i)
{

if(umap.find(v[i]) == umap.end())
{
	umap[v[i]] = count;
	count ++;

}

}


unordered_map<int,int>:: iterator itr;
for(itr = umap.begin();itr!= umap.end(); ++itr)
		cout<<itr->first<<" ";




}