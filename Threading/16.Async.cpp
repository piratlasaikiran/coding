#include <bits/stdc++.h>
using namespace std;
typedef long long int ull;

ull findOdd(ull start, ull end){
    ull oddSum=0;
    cout << "Thread ID: " << std::this_thread::get_id() << endl;
    for(ull i=start; i<end; i++){
        if(i & 1)
            oddSum+=i;
    }
    return oddSum;
}

int main(){
    ull start=0, end=190000;

    cout << "Thread Created.!" << endl;
    cout << "Thread ID: " << std::this_thread::get_id() << endl;
    std::future<ull> OddFuture = std::async(std::launch::async, findOdd, start, end); // runs in newly created task (task will be create in .get call)
    // can be run with std::launch::deferred -> to run in same thread. 
    
    cout << "Waiting for result." << endl;
    cout << "OddSum is: " << OddFuture.get() << endl;
    cout << "Completed!" << endl;
    
    return 0;     
}