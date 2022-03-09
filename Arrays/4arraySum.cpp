#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int, int> firstMapper;
        int nums1Size = nums1.size();
        int nums2Size = nums2.size();
        for(int i=0; i<nums1Size; i++){
            for(int j=0; j<nums2Size; j++){
                firstMapper[nums1[i]+nums2[j]]++;
            }
        }
        int sum4Count = 0;
        int nums3Size = nums3.size();
        int nums4Size = nums4.size();
        for(int i=0; i<nums3Size; i++){
            for(int j=0; j<nums4Size; j++){
                sum4Count+=(firstMapper[-(nums3[i]+nums4[j])]);
            }
        }
        return sum4Count;
    }
};

int main(){
    Solution obj;
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {-2,-1};
    vector<int> nums3 = {-1,2};
    vector<int> nums4 = {0,2};
    auto answer = obj.fourSumCount(nums1, nums2, nums3, nums4);
    cout << "Answer: " << answer << endl;
    return 0;
}