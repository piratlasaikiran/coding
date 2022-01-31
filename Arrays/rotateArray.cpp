#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        vector<int>::iterator partitionIter = nums.begin();
        int partitionIndex = n-k;
        while(partitionIndex-- > 0){
            ++partitionIter;
        }
        auto partitionIterCopy = partitionIter;
        reverse(partitionIter++, nums.end());
        reverse(nums.begin(), partitionIterCopy);
        reverse(nums.begin(), nums.end());

    }
};

int main(){
    Solution obj;
    vector<int> nums = {1,2,3,4,5,6,7};
    obj.rotate(nums, 3);
    cout << "Answer: ";
    for(auto i:nums){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}