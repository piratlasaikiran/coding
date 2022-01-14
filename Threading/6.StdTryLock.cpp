// you can lock multiple mutex at a same time.
// Syntax = std::try_lock(m1, m2, m3, ....., mn)
// all locked -> returns -1 else returns index() based index) of mutex which failed to get locked.
// failure will result in unlocking all the mutex it locked before


#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int x=0, y=0;
std::mutex m1, m2;

void doSomeWorkForSeconds(int seconds){
    std::this_thread::sleep_for(chrono::seconds(seconds));
}

void incrementXY(int& XorY, std::mutex& m, const char* desc){
    for(int i=0; i<5; i++){
        m.lock();
        ++XorY;
        cout << desc << XorY << endl;
        m.unlock();
        doSomeWorkForSeconds(1);
    }
}

void consumeXY(){
    int useCount = 5;
    int XplusY = 0;
    while(1){
        int lockResult = std::try_lock(m1, m2);
        if(lockResult == -1){
            if(x!=0 && y!=0){
                --useCount;
                XplusY = XplusY + x + y;
                x=0;
                y=0;
                cout << "XplusY: " << XplusY << endl;
            }
            m1.unlock();
            m2.unlock();
        }
        if(useCount==0)
            break;
    }
}



int main(){
    std::thread t1(incrementXY, std::ref(x), std::ref(m1), "X ");
    std::thread t2(incrementXY, std::ref(y), std::ref(m1), "Y ");
    std::thread t3(consumeXY);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}