#include <iostream>
#include <thread>
using namespace std;

void fun1()
{
    for (int i = 0; i < 100; i++)
    {
        cout << "Plus";
    }
}

void fun2()
{
    for (int i = 0; i < 100; i++)
    {
        cout << " MINUS";
    }
}

int main()
{

    thread worker1(fun1);
    thread worker2(fun2);

    //  we can pass parameters inside function which is executed by thread
    // sytax ->   thread constructor_name(function_name, parameter);

    // thread worker3(fun1, 'B');

    //  we can check wheater thread is joinable or not by using a funciton called  jonable()

    if (worker1.joinable() && worker2.joinable())
    {

        worker1.join();
        worker2.join();
    }

    return 0;
}