#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

std::mutex m1;
int buffer = 0;

// void task(const char* threadnumber, int loopFor){
//     std::unique_lock<mutex> lock(m1);
//     for(int i=0; i<loopFor; i++){
//         buffer++;
//         cout << threadnumber << " " << buffer << endl;
//     }
// }

void task(const char* threadnumber, int loopFor){
    std::unique_lock<mutex> lock(m1, std::defer_lock);
    lock.lock();
    for(int i=0; i<loopFor; i++){
        buffer++;
        cout << threadnumber << " " << buffer << endl;
    }
}

int main(){
    std::thread t1(task, "T0", 10);
    std::thread t2(task, "T1", 10);

    t1.join();
    t2.join();

    return 0;
} 