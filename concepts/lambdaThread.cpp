#include <iostream>
#include <thread>

using namespace std;

int main()
{

    auto lambda= [] (int x)
    {
        cout << "Hello from thread \n";
        cout << "Argument passed in " << x << endl;
    };

    thread t1(lambda, 100);
    t1.join();

    cout << " Hello from main()";


    return 0;
}