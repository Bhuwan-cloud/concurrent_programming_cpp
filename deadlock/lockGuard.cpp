#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

//  lets create  a gobal variable called gLock 

mutex gLock;

static int shared_value = 0; 
void shared_value_increment(){
    gLock.lock(); // gLock prevents the threads from accessing the common resources at single time ; it locks and then unlock

        try
        {
            shared_value = shared_value + 1;
            throw " dangrous abort";
        }
        catch(...)
        {
            cout << " handle Exception";
            gLock.unlock(); 
            return ;
        }
        
    gLock.unlock(); 
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