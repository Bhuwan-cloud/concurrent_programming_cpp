#include <iostream>
#include <thread>
#include <map>
#include <string>
using namespace std;

void refreshForecast(map<string, int> forecastMap)
{
    while (true)
    {
        //  we are getting forecastMap vartiable in 'item ' object and it is iterating through each element of pairs.
        for (auto& item : forecastMap)
        {
            item.second++;
            cout << item.first << " , " << item.second << endl;
            this_thread::sleep_for(2000ms);
        }
    }
}

int main()
{

    map<string, int> forecastMap = {
        {"New York", 15},
        {"Mumbai", 20},
        {"Berlin", 17},
        {"Hamburg", 15}};

    thread bgworker(refreshForecast, forecastMap);

    bgworker.join();

    return 0;
}
