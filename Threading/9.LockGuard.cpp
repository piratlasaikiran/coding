#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

std::mutex m1;
int buffer = 0;

void task(const char* threadnumber, int loopFor){
    std::lock_guard<mutex> lock(m1);
    // m1.lock();
    for(int i=0; i<loopFor; i++){
        buffer++;
        cout << threadnumber << " " << buffer << endl;
    }
    // m1.unlock();
}

int main(){
    std::thread t1(task, "T0", 10);
    std::thread t2(task, "T1", 10);

    t1.join();
    t2.join();

    return 0;
}