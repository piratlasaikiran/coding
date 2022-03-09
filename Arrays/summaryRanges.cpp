#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    string intervalMaker(string start, string end){
        string interval = {};
        if(start == end){
            interval = start;
        }
        else{
            interval = start + "->" + end;
        }
        return interval;
    }
    
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> answer;
        for(int i=0; i<n; i++){
            string intervalStart = to_string(nums[i]);
            string intervalEnd = to_string(nums[i]);
            int k = i+1;
            while(k<n && nums[k] == nums[k-1]+1){
                intervalEnd = to_string(nums[k]);
                k++;
            }
            string curInterval = intervalMaker(intervalStart, intervalEnd);
            answer.push_back(curInterval);
            i = k-1;
        }
        return answer;
    }
};

int main(){
    vector<int> nums = {0,1,2,4,5,7};
    Solution obj;
    auto answer = obj.summaryRanges(nums);
    cout << "Answer: " << endl;
    for(auto i:answer){
        cout << i << endl;
    }
    return 0;
}