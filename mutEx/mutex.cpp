#include <iostream>
#include <thread>
#include <vector>
//  mutex class header prevents from sharing common data to all intialized threads by scheduling
#include <mutex>

using namespace std;

//  lets create  a gobal variable called gLock 

mutex gLock;

//  this is the shared value for all threads 
static int shared_value = 0; 
//  this fucntion increments data at each time 
void shared_value_increment(){
    gLock.lock(); // gLock prevents the threads from accessing the common resources at single time ; it locks and then unlock
        shared_value = shared_value + 1;
        //  we can have multiple shared values which all will be protected by mutex object "gLock"
    gLock.unlock();
}

int main()
{

    vector<thread> threads;
//  it initializes 100 threads and each are trying to acccess a common resources called shared_object  
//  so it creates a problem of data race ... and this problem is solved a mutex object 
//  mutex solves it by mutuallly sharing key for the common data  to all threads
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