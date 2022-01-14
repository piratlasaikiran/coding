#include <bits/stdc++.h>
using namespace std;

std::condition_variable cv;
std::mutex m;
int numCount=0;

void printOdd(){
    while(numCount<100){
        std::unique_lock<mutex> ul(m);
        cv.wait(ul, []{return numCount%2==1 ;});
        cout << numCount << endl; 
        numCount++;
        ul.unlock();
        cv.notify_all();
    }
}

void printEven(){
    while(numCount<100){
        std::unique_lock<mutex> ul(m);
        cv.wait(ul, []{return numCount%2==0 ;});
        cout << numCount << endl; 
        numCount++;
        ul.unlock();
        cv.notify_all();
    }
}

int main(){
    std::thread t1(printEven);
    std::thread t2(printOdd);
    t1.join();
    t2.join();
    return 0;
}