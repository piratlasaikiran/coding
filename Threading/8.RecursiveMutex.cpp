#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

std::recursive_mutex m1;
int buffer = 0;

void recursion(char c, int loopFor){
    if(loopFor<0)
        return;

     m1.lock();
     cout << "ThreadID " << c << " " << buffer++ << endl;
     recursion(c, --loopFor);
     m1.unlock();
}

int main(){
    std::thread t1(recursion, '1', 10);
    std::thread t2(recursion, '2', 10);

    t1.join();
    t2.join();
    return 0;
}