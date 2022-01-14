#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;
ull OddSum = 0;
ull EvenSum = 0;

void findEven(ull start, ull end) {
	for (ull i = start; i <= end; ++i){
		if (!(i & 1)){
			EvenSum += i;
		}
	}
}
 
void findOdd(ull start, ull end) {
	for (ull i = start; i <= end; ++i){
		if (i & 1){
			OddSum += i;
		} 
	}
}

int main() {
 

    ull startVal = 0;
    ull endVal = 1900000000;
 
    auto startTime = high_resolution_clock::now(); 
 
	// // WITH THREAD
    std::thread t1(findEven, startVal, endVal);
    std::thread t2(findOdd, startVal, endVal);

    t1.join();
    t2.join();

 
	// // WITHOUT THREAD
	findEven(startVal, endVal);
	findOdd(startVal, endVal);

    auto stopTime = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stopTime - startTime);
 
	cout << "OddSum : " << OddSum << endl;
	cout << "EvenSum : " << EvenSum << endl;
 
	cout << "Sec: " << duration.count()/1000000 << endl;
 
	return 0;
}