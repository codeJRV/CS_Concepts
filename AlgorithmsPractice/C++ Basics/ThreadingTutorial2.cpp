#include <iostream>
#include <thread>
#include <string>

using namespace std;

void function_1()
{
    std::cout << "Beauty is only fucking skin deep" << std::endl;
}

class Fctor{                                    // Functors are classes made just to hold a function. They are usually function objects;
                                                // it is done by overloading the () operator.
    public:
        void operator()(string& msg){
            // for (int i =0 ; i >-100; i--)
            //     std::cout<<"from t1"<<i<<endl;
            std::cout<<"T1 says :"<<msg<<endl;
            msg = "Yaay, change is the only constant";
        }
};

int main()
{   
    Fctor fct;
    string s  = "Those who mind, dont matter,  and those who matter, dont mind";

    cout<<std::thread::hardware_concurrency()<<endl;

    //std::thread t1(fct,s); //t1 starts running from here
    std::thread t2((Fctor()),std::ref(s));                              //This is bad for memory management between two threads, the right way to do this is by using std::move(s)                                    
        t2.join();
    try
    {                                                                   //in the case that the main function or any parent thread fails due to some reason, we still need  to end the 
        int i = 100;                                                    // running thread hence we are calling the try catch blocks to do this for us.
        //while (--i)
            cout << "from main:: " << s << endl;
    }
    catch (...)
    {
        //t1.join();

        throw;
    }

    //t1.join();
    // t2.join();
    return 0;
}


//Alterntive approach would be using Resource Aquisition is Initialization approach

