#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:

    struct position{
        int x;
        int y;
        int moves;
        position() {}
        position(int x, int y, int moves) : x(x), y(y), moves(moves) {}
    };

    int x[8] = {2,2,1,-1,-2,-2,1,-1};
    int y[8] = {1,-1,2,2,1,-1,-2,-2};

    bool validPosition(int xPos, int yPos, int N){
        if(1<=xPos && xPos<=N && 1<=yPos && yPos<=N)
            return true;
        return false;
    }

    int minStepToReachTarget(int knightPos[], int targetPos[], int N, vector<vector<bool>>& visited){
        queue<position> knightPositions;

        knightPositions.push(position(knightPos[0], knightPos[1], 0));
        visited[knightPos[0]][knightPos[1]] = true;
        while(!knightPositions.empty()){
            position tempPosKnight = knightPositions.front();
            int curKnightPosX = tempPosKnight.x;
            int curKnightPosY = tempPosKnight.y;
            int curMoves = tempPosKnight.moves;
            knightPositions.pop();
            if(curKnightPosX==targetPos[0] && curKnightPosY==targetPos[1]){
                        return curMoves;
            }
            for(int k=0; k<8; k++){
                int nextKnightPosX = x[k] + curKnightPosX;
                int nextKnightPosY = y[k] + curKnightPosY;
                if(validPosition(nextKnightPosX, nextKnightPosY, N) && !visited[nextKnightPosX][nextKnightPosY]){                    
                    visited[nextKnightPosX][nextKnightPosY] = true;
                    knightPositions.push(position(nextKnightPosX, nextKnightPosY, curMoves+1));
                    cout << "Pushing: " << nextKnightPosX << " " <<  nextKnightPosY << endl;
                }
            }
        }
        return -1;
    }
};

    int main(){
    Solution obj;

    
    // TreeNode* root = new TreeNode(1);
    // root->left = new TreeNode(9);
    // root->right = new TreeNode(2);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(4);
    // root->right->left = new TreeNode(15);
    // root->right->right = new TreeNode(3);
    // root->right->right->right = new TreeNode(4);

    int knightPos[] = { 1, 1 };
    int targetPos[] = { 30, 30 };
    int N=30;
    vector<vector<bool>> visited(N+1, vector<bool>(N+1, false));
    auto answer = obj.minStepToReachTarget(knightPos, targetPos, N, visited);

    cout << "Answer: " << answer << endl;

    // for(auto j:answer)
    //     cout << j << " ";
    // cout << endl;

    return 0;
}