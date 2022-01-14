#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int oddNum = 0;
        int evenNum = 0;
        for(int i=0; i<position.size(); i++){
            if(position[i]%2 == 0)
                evenNum++;
            else
                oddNum++;
        }
        return oddNum>evenNum ? oddNum : evenNum;
    }
};

int main(){
    Solution obj;

    vector<int> position = {3,3,1,2,2};
    auto answer = obj.minCostToMoveChips(position);

    cout << "Answer: " << answer << endl;

    return 0;
}