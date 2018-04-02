#include<iostream>
#include<memory>

using namespace std;

int main()
{


    {

        std::unique_ptr<int> someint = std::make_unique<int>();                     //Only one refcount
        std::shared_ptr<int> somesharedint = std::make_shared<int>();               //Shared implies there is a refcount increment system
        std::weak_ptr<int> weak_potr = somesharedint;                               //weak pointer doesnt increase the refcount


    }

    cout<<endl;
}