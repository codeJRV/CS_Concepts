//
// Created by jrv on 3/18/18.

#include <iostream>
#include <bits/stdc++.h>
#include <boost/unordered_map.hpp>

typedef boost::unordered::unordered_map<std::string,int> umap;

//practice maps

using namespace std;

int main()
{

   int n;
   cin>>n;
   umap mymap;
   while(n--)
   {

       string name;
       int number;
       cin>>name>>number;
       mymap[name]=number;

   }
   string name;
   cout<<endl;
   while (cin>>name)
   {


       if(mymap[name])
       {
           cout<<name<<"="<<mymap[name]<<endl;
       } else
       {
           cout<<"Not found\n";
       }
   }

}
