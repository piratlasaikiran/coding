#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> xCord = {0, 1, 0, -1};
    vector<int> yCord = {1, 0, -1, 0};

    bool isRobotBounded(string instructions) {
        int n = instructions.size();
        int curDir = 0;
        int curX = 0, curY = 0;
        for(int i=0; i<n; i++){
            if(instructions[i] == 'G'){
                curX = curX + xCord[curDir];
                curY = curY + yCord[curDir];
            }
            else if(instructions[i] == 'R'){
                curDir = (curDir + 1)%4;
            }
            else{
                curDir = (curDir + 3)%4;
            }
        }
        cout << "X: " << curX << " Y: " << curY << endl;

        return ((curX == 0) && (curY == 0));
    }
};

int main(){
    string inst = "GL";
    Solution obj;
    auto answer = obj.isRobotBounded(inst);
    cout << "Answer: " << answer << endl;
    return 0;
}