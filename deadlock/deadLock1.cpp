#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

//  lets create  a gobal variable called gLock

mutex gLock;

static int shared_value = 0;
void shared_value_increment()
{
    // here we can throw an exception and putting gLock under the catch block to prevent it from deadlock

    //  when threads are trying to access the recource one thread got access to critical section and
    // rest of the threads are getting exceptiopn i.e deadlock

    //  to get rid of this exception and deadlock we can use lock_guard() as following
    //  basically lock_guard is a wrapper class for mutex
    //  lock_guard releases all the exceptions from the code

    lock_guard<mutex> locakGuard(gLock);

    try
    {
        shared_value = shared_value + 1;
        throw " dangrous abort";
    }
    catch (...)
    {
        cout << " Exception thrown by  thread \t \t";
        return;
    }
    //  we can also get rid of this try catch block in deadLock2.cpp file 

    //  if we dont unlock our Mutex object function( as above) then it will be considered as deadlock
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