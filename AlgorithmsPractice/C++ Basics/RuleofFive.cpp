#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class C{

public:


    C(){
      cout<<"1. Constructor called\n";  
    };

    ~C()
    {
        cout<<"2. Destructor called\n";
    }

    C(const C &c2) {
        cout<<"3. Copy Constructor called\n";  
    }

    C& operator = (const C &c2){
        cout<<"4.Copy Assignment Operator called\n";  
    }

    C(C&& otherSea) 
    {
        cout<<"5. Move Constructor called\n";  
    }


};



int main()
{

    cout<<"This is the rule of five\n\n\n";
    {
    C* mySea = new C() ;
    C* otherSea  = mySea;
    C someSea = *mySea;
    C someOtherSea;
    someOtherSea  = someSea;

    delete mySea;
    }




}