#include <iostream>
#include <thread>

using namespace std;

void foo(int Z)
{
    for (int i = 0; i < Z; i++)
        cout << "Thread using function pointer as a callable method \n";
}

class thread_obj
{
  public:
    void operator()(int X)
    {
        for (int i = 0; i < X; i++)
            cout << "Thread using function object as callable\n";
    }
};

int main()
{
    thread th1(foo, 30);
    thread th2(thread_obj(), 30);

    //Lets try out a lambda

    auto f = [](int x) {
        for (int i = 0; i < x; i++)
            cout << "thread using lambda expression as callable\n";

    };

    thread th3(f,30);
    th1.join();
    th2.join();
    th3.join();
    return 0;




}