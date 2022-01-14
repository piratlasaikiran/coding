#include <bits/stdc++.h>
using namespace std;
typedef long long int ull;

void findOdd(std::promise<ull>&& OddSumPromise, ull start, ull end){
    ull oddSum=0;
    for(ull i=start; i<end; i++){
        if(i & 1)
            oddSum+=i;
    }
    OddSumPromise.set_value(oddSum);
}

int main(){
    ull start=0, end=190000;

    std::promise<ull> OddSum;
    std::future<ull> OddFuture = OddSum.get_future();

    cout << "Thread Created.!" << endl;
    std::thread t1(findOdd, std::move(OddSum), start, end);

    cout << "Waiting for result." << endl;

    cout << "OddSum is: " << OddFuture.get() << endl;

    cout << "Completed!" << endl;
    t1.join();

    return 0;     
}