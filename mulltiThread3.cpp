#include <iostream>
#include <thread>
using namespace std;

void foo(int z)
{

    for (int i = 1; i < z; i++)
    {
        cout << " Thread using function pointer as callable";
    }
}

//  callable object 

class thread_object{
    public: 
        void operator()(int x){
            for(int i = 1; i< x; i++){
                cout << "Thread using function abject as callable  ";
            }
        }

};

int main()
{
    cout << " Thread 1 & 2 are  operating independently ";
     cout << endl;
    //  this thread is launached by function pointer 
    thread t1(foo, 3);
     cout << endl;
    // this therad is launched by fucntion object 
    thread t2( thread_object(), 3);
     cout << endl;

    auto f = [](int x){
        for(int i = 1; i <x ; i++){
            cout << "thread using lambda expression as callable ";
        }
    };

    thread t3(f, 3);
     cout << endl;

    t1.join(); 
    t2.join();
    t3.join(); 



    return 0;
}
