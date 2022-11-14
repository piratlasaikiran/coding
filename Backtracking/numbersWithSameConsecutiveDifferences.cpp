#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        
    }
};

int main(){
    int n = 3, k = 7;
    Solution obj;
    auto answer = obj.numsSameConsecDiff(n, k);
    cout << "Answer: " << endl;
    for(auto i:answer){
        cout << i << endl;
    }
    return 0;
}