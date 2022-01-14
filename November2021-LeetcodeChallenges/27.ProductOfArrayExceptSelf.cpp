#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> prev(n, 1);
        vector<int> next(n, 1);
        for(int i=1; i<n; i++){
            cout << "Prev[i-2] " << prev[i-2] << " nums[i-1] " << nums[i-1] << endl;
            prev[i] = prev[i-1]*nums[i-1];
            next[n-1-i] = next[n-i]*nums[n-i];
            cout << "Prev: " << prev[i] << " for i: " << i << endl;
        }
        for(auto i:prev)
            cout << i << " ";
        cout << endl;

        for(auto i:next)
            cout << i << " ";
        cout << endl;

        vector<int> answer(n);
        for(int i=0; i<n; i++)
            answer[i] = prev[i]*next[i];

        return answer;
    }
};

int main(){
    vector<int> nums = {1,2,3,4};
    Solution obj;
    auto answer = obj.productExceptSelf(nums);
    for(auto i:answer)
        cout << i << " ";
    cout << endl;

    return 0;

}