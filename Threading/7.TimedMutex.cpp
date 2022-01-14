#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int myAmount = 0;
std::timed_mutex m;

void increment(int i){
    // if(m.try_lock_for(std::chrono::seconds(2))){
        auto now = std::chrono::steady_clock::now();
        if(m.try_lock_until(now + std::chrono::seconds(2))){ // giving a reference time rather than "time from now". Rest everything is same.
        ++myAmount;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        m.unlock();
    }
    else{
        cout << "Couldn't enter thread: " << i << endl;
    }
}

int main(){
    std::thread t1(increment, 1);
    std::thread t2(increment, 2);

    t1.join();
    t2.join();

    cout << "myAmount: " << myAmount << endl;

    return 0;
}