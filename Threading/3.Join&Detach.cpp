#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void run(int n){
    while(n--){
        cout << n << " ";
    }
    cout << endl;
    std::this_thread::sleep_for(chrono::seconds(3));
}

int main(){

    /*
    thread t1(run, 5);
    cout << "Before Join" << endl;
    t1.join();
    if(t1.joinable())
        t1.join(); // Double join will terminate program.!!
    cout << "After Join" << endl;
    return 0;
    */

    thread t1(run, 5);
    cout << "Before Join" << endl;
    t1.detach();
    if(t1.joinable())
        t1.detach();
    cout << "After Join" << endl;
    return 0;

}