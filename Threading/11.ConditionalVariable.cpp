#include <bits/stdc++.h>
using namespace std;

std::condition_variable cv;
std::mutex m;
long balance = 0;


void addMoney(int money){
    std::lock_guard<mutex> lg(m);
    balance+=money;
    cout << "Amount added. Current Balance: " << balance << endl;
    cv.notify_all();
}

void withdrawMoney(int money){
    std::unique_lock<mutex> ul(m);
    cv.wait(ul, []{return balance>0 ? true : false;});
    if(balance >= money){
        balance-=money;
        cout << "Amount deducted: " << money << endl;
    }
    else{
        cout << "Can't deduct money" << endl;
    }
    cout << "Current balance: " << balance << endl;
}

int main(){
    std::thread t1(addMoney, 500);
    std::thread t2(withdrawMoney, 500);

    t1.join();
    t2.join();

    return 0;
} 