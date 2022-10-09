
//  atomic template is used for applying "one at a time pinciple to threads "

#include <iostream>
#include <thread>
#include <vector>
#include <atomic>

using namespace std;

//  w can update shared value by using atomic template by making a varible atomic
static atomic<int> shared_value = 0;
void shared_value_increment()
{
    shared_value ++;
    //  if we use shared_value = shared_value + 1;  we will get a deadlock or daa race 
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