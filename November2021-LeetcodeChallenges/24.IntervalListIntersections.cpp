#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {

    int firstListSize = firstList.size();
    int secondListSize = secondList.size();
    int i=0;
    int j=0;
    vector<vector<int>> answer;
    while(i<firstListSize && j<secondListSize){
        int aStart = firstList[i][0];
        int aEnd = firstList[i][1];
        int bStart = secondList[j][0];
        int bEnd = secondList[j][1];

        cout << aStart << "  " << aEnd << " " << bStart << " " << bEnd << endl;
        if(aEnd < bStart){
            i++;
            continue;
        }

        if(bEnd < aStart){
            j++;
            continue;
        }

        int commonStart = max(aStart, bStart);
        int commonEnd = min(aEnd, bEnd);

        if((commonStart == aStart) && (commonEnd == aEnd)){
            i++;
        }
        else if((commonStart == bStart) && (commonEnd == bEnd)){
            j++;
        }
        else if((commonEnd == bEnd)){
            j++;
        }
        else if((commonEnd == aEnd)){
            i++;
        }

        if(commonEnd >= commonStart){
            cout << "[" << commonStart << "," << commonEnd << "]" << endl;
            answer.push_back({commonStart, commonEnd});
        }
    }

    return answer;  
    }
};

int main(){
    Solution obj;
    vector<vector<int>> grid1 = {{8,15}};
    vector<vector<int>> grid2 = {{2,6},{8,10},{12,20}};

    auto answer = obj.intervalIntersection(grid1, grid2);
    for(auto i:answer){
        for(auto j:i)
            cout << j << " ";
        cout << endl;
    }
    cout << endl;
    return 0;
}