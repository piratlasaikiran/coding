#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> dp;
class Solution{
    public:

    int EggDroppingRecursive(int floors, int eggs ){
        if(floors == 0 || floors ==1 || eggs ==0 || eggs == 1)
            return floors;
        int mini = INT_MAX;
        for(int k=1; k<=floors; k++){
            mini = min(mini, 1+max(EggDroppingRecursive(k-1, eggs-1), EggDroppingRecursive(floors-k, eggs)));
        }   
        return mini;
    }
};

int main(){
    Solution obj;
    int eggs = 2;
    int floors = 4;
    auto answer = obj.EggDroppingRecursive(floors, eggs);
    cout << "Answer is: " << answer << endl;
    return 0;
}