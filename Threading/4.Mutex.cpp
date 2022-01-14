#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int myAmount = 0;
std::mutex m;

void addMoney(){
    m.lock();
    ++myAmount;
    m.unlock();
}

int main(){
    std::thread t1(addMoney);
    std::thread t2(addMoney);

    t1.join();
    t2.join();

    cout << "Final amount is: " << myAmount << endl;

    return 0;
}