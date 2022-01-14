#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool smallNumCount(int mid, int m, int n, int k){
        int count=0;
        for(int i=0; i<m; i++)
            count += min(mid/(i+1), n);
        
        return count >= k;
    }

    int findKthNumber(int m, int n, int k) {
        int left = 1;
        int right = m*n;
        int mid, answer;
        while(left<right){
            mid = left + (right-left)/2;
            if(smallNumCount(mid, m, n, k))
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
};

int main(){
    Solution obj;

    auto answer = obj.findKthNumber(3, 3, 6);
    // for(auto i:answer){
    //     for(auto j:i)
    //         cout << j << " ";
    // cout << endl;
    // }
    cout << "Answer: " << answer << endl;
    return 0;
}