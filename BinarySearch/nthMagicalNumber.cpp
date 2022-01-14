#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // int nthMagicalNumber(int n, int a, int b) {

    //     int modulo = 1e9+7;
    //     set<int> divisibleNumbers;
    //     for(int i=0; i<n; i++){
    //         int numA = a*(i+1);
    //         if(divisibleNumbers.find(numA) == divisibleNumbers.end())
    //             divisibleNumbers.insert(numA);
    //     }

    //     for(int i=0; i<n; i++){
    //         int numB = b*(i+1);
    //         if(divisibleNumbers.find(numB) == divisibleNumbers.end())
    //             divisibleNumbers.insert(numB);
    //     }

    //     int count=0;
    //     long long int answer;
    //     for(auto it = divisibleNumbers.begin(); it != divisibleNumbers.end(); ++it){
    //         count++;
    //         if(count==n)
    //             answer = *it;
    //     }
    //     return answer;
    // }

    int gcd(int a, int b){
        if (a == 0)
            return b;
        if (b == 0)
            return a;
    
        if (a == b)
            return a;
    
        if (a > b)
            return gcd(a-b, b);
        return gcd(a, b-a);
    }

    long long int getPosition(int n, int a, int b, int lcm){
        return n/a + n/b - n/lcm;
    }

    int nthMagicalNumber(int n, int a, int b) {
        int lcm = (a*b)/gcd(a, b);
        long long int low = 1;
        long long int high = pow(10, 18) + 1;
        while(low < high){
            
        }
    }
};

int main(){
    Solution obj;
    auto answer = obj.nthMagicalNumber(3, 6, 4);
    cout << "Answer: " << answer << endl;
    return 0;
}