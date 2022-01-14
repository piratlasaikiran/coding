#include <bits/stdc++.h>
using namespace std;

std::mutex m;
std::condition_variable cv;
deque<int> buffer;
#define bufferSize 50

void producer(int val){
    while(val){
        std::unique_lock<std::mutex> ulock(m);
        cv.wait(ulock, []{return buffer.size()<bufferSize ;});
        buffer.push_back(val);
        cout << "Produced: " << val << endl;
        val--;
        ulock.unlock();
        cv.notify_one();
    }
}

void consumer(){
    while(1){
        std::unique_lock<mutex> ulock(m);
        cv.wait(ulock, []{return buffer.size()>0;});
        int val = buffer.back();
        buffer.pop_back();
        cout << "Consumed: " << val << endl;
        ulock.unlock();
        cv.notify_one();
    }
}

int main(){
    std::thread t1(producer, 100);
    std::thread t2(consumer);

    t1.join();
    t2.join();

    return 0;
}