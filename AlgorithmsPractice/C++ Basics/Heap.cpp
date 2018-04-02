#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{

    vector <int> v1 = { 40, 30, 25, 35,15};

    make_heap(v1.begin(), v1.end());
    v1.push_back(70);

    //Print heap 

    for(int i = 0; i < v1.size(); i++)
        cout<<v1[i]<<endl;

    cout<<endl;
  
    v1.push_back(10);

    for(int i = 0; i < v1.size(); i++)
        cout<<v1[i]<<endl;
    
    cout<<endl;

    for(int i = 0; i < v1.size(); i++)
        cout<<v1[i]<<endl;

    sort_heap(v1.begin(), v1.end());

cout<<endl;

    for(int i = 0; i < v1.size(); i++)
        cout<<v1[i]<<endl;



}