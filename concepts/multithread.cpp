#include<iostream>
#include<thread>

using namespace std;

void test(int x){
    cout << "Hello from thread \n";
    cout << "Argument passed in " << x << endl;
}

int main(){


    thread myThread(&test, 100);
    if(myThread.joinable()){
        myThread.join();
    }
    cout << " Hello from my main() thread ";

    return 0;
}