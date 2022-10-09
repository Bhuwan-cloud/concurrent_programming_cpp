#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

mutex gLock;

static int shared_value = 0;
void shared_value_increment()
{

    lock_guard<mutex> locakGuard(gLock);

    shared_value = shared_value + 1;

}

int main()
{
    // ----------------------------------------------------------
    vector<thread> threads;

    for (int i = 0; i < 100; i++)
    {
        threads.push_back(thread(shared_value_increment));
    }
    for (int i = 0; i < 100; i++)
    {
        threads[i].join();
    }
    // -------------------------------------------------------------
    cout << " shared value is " << shared_value;

    return 0;
}