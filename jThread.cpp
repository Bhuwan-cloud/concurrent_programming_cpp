#include <iostream>
#include <thread>
#include <vector>

//  jthreas are only introduced in c++ 20 onowards ow i have only c++ 11 so i cant use jthread 

using namespace std;
int main()
{
    auto lambda = [](int x)
    {
        cout << " Hello from labmbda thread id: " << this_thread::get_id() << endl;
        cout << " Argument passed in :" << x << endl
             << endl;
    };
    //  initializing a vector to get dynamic array
    // syntax ->  vector<type> name_of_array;
    vector<jthread> d_arr;

    for (int i = 0; i < 10; i++)
    {
        //  genearating 10 arrays & lambda is fucntion passed in thread() constructor with i arg
        d_arr.push_back(jthread(lambda, i));
    }
    //  after initalizing 10 threads we are now joining them with main thread
    for (int i = 0; i < 10; i++)
    {
        d_arr[i].join();
    }

    cout << " main() is running ";

    return 0;
}