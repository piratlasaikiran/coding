#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int longestComponentLength=1;

    bool twoNumbersHaveCommonFactor(int num1, int num2){
        int smallNum = min(num1, num2);
        for(int i=2; i<=smallNum; i++){
            if(num1%i == 0 && num2%i == 0)
                return true;
        }
        return false;
    }

    void findLongestComp(vector<int>& nums, set<int>& visited, int n, int startNum, map<int, vector<int>> factorMap, int curCompSize){

        if(curCompSize > longestComponentLength){
                longestComponentLength = curCompSize;
        }

        if(visited.size() == n)
            return;
        visited.insert(startNum);
        vector<int> factors = factorMap[startNum];
        for(auto factor:factors){
            if(visited.count(factor) == 0){
                visited.insert(factor);
                findLongestComp(nums, visited, n, factor, factorMap, curCompSize+1);
                visited.erase(factor);
            }
        }
        
    }

    int largestComponentSize(vector<int>& nums) {
        map<int, vector<int>> factorMap;
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i != j){
                    if(twoNumbersHaveCommonFactor(nums[i], nums[j]))
                        factorMap[nums[i]].push_back(nums[j]);
                }
            }
        }
        for(auto i:factorMap){
            cout<<i.first<< " -> ";
            for(auto j:i.second)
                cout << j << " ";
            cout << endl;
        }
        set<int> visited;
        for(int i=0; i<n; i++)
            findLongestComp(nums, visited, n, nums[i], factorMap, 1);
        return longestComponentLength;
    }
};

int main(){
    Solution obj;

    vector<int> nums = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    auto answer = obj.largestComponentSize(nums);
    cout << "Answer: " << answer << endl;
    return 0;
}