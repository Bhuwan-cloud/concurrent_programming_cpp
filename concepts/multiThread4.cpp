#include <iostream>
#include <thread>

using namespace std;

void function1(int num)
{
    for (int i = 1; i < num; i++)
    {
        cout << "Thread 1 is runing to : " << i << endl;
        this_thread::sleep_for(1000ms);
    }
}

void function2(int arg)
{
    for (int i = 1; i < arg; i++)
    {
        cout << " Thread2 is running to: " << i << endl;
        this_thread::sleep_for(1000ms);
    }
}

int main()
{

    // function1(5);
    // function2(6);

    thread t1(function1, 100);
    thread t2(function2, 100);

    if (t1.joinable() && t2.joinable())
    {
        t1.join();
        t2.join();
    }

    return 0;
}