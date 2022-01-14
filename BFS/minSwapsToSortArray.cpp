#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    int minSwapsRequired(vector<int>& nums){
        vector<int> sortedArray = nums;
        sort(sortedArray.begin(), sortedArray.end());
        map<int, int> finalIndices;
        int n = nums.size();
        for(int i=0; i<n; i++){
            finalIndices[sortedArray[i]] = i;
        }
        vector<bool> counted(n, false);
        int cycleSize=0;
        int answer=0;
        for(int i=0; i<n; i++){
            if(sortedArray[i] == nums[i]){
                counted[i] = true;
                continue;
            }
            cycleSize = 0;
            int j=i;
            while(!counted[j]){
                counted[j] = true;
                cycleSize++;
                j = finalIndices[nums[j]];
            }
            if(cycleSize>0){
                cout << "Adding: " << cycleSize-1 << endl;
                answer+=(cycleSize-1);
            }
        }
        return answer;
    }
};

int main(){
    
    vector<int> nums = {1, 5, 4, 3, 2};
    Solution obj;

    auto answer = obj.minSwapsRequired(nums);
    cout << "Answer: " << answer << endl;

    return 0;

}