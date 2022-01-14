#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int> nextBig;
        map<int, int> nextBigMapper;
        for(int i=n-1; i>=0; i--){
            nextBigMapper[nums2[i]] = -1;
            while(!nextBig.empty() && nextBig.top() <= nums2[i]){
                nextBig.pop();
            }
            if(!nextBig.empty()){
                nextBigMapper[nums2[i]] = nextBig.top();
            }

            nextBig.push(nums2[i]);
        }
        vector<int> answer;
        for(auto element:nums1){
            answer.push_back(nextBigMapper[element]);
        }
        return answer;
    }
};

int main(){
    Solution obj;
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};

    auto answer = obj.nextGreaterElement(nums1, nums2);
    for(auto i:answer)
        cout << i << " ";
    cout << endl;
}