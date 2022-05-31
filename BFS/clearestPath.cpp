#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(int i,int j,int n){
        if(i<0||j<0||i>=n||j>=n) return 0;
        return 1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& mat) {
        int i,n=mat.size(),x,y,t,val=mat[0][0];
        if(val==1) return -1;
        int vis[n][n];
        memset(vis,0,sizeof(vis));
        queue<vector<int>> q;
        q.push({0,0,0});
        while(q.size()){
            vector<int> v=q.front(); q.pop();
            t=v[0]; x=v[1]; y=v[2];
            if(x==n-1 && y==n-1) return t+1;
            if(isSafe(x+1,y,n) && mat[x+1][y]==0 && vis[x+1][y]!=1){
                q.push({t+1,x+1,y}); vis[x+1][y]=1;
            }
            if(isSafe(x-1,y,n) && mat[x-1][y]==0 && vis[x-1][y]!=1){
                q.push({t+1,x-1,y}); vis[x-1][y]=1;
            }
            if(isSafe(x+1,y+1,n) && mat[x+1][y+1]==0 && vis[x+1][y+1]!=1){
                q.push({t+1,x+1,y+1}); vis[x+1][y+1]=1;
            }
            if(isSafe(x,y+1,n) && mat[x][y+1]==0 && vis[x][y+1]!=1){
                q.push({t+1,x,y+1}); vis[x][y+1]=1;
            }
            if(isSafe(x-1,y+1,n) && mat[x-1][y+1]==0 && vis[x-1][y+1]!=1){
                q.push({t+1,x-1,y+1}); vis[x-1][y+1]=1;
            }
            if(isSafe(x,y-1,n) && mat[x][y-1]==0 && vis[x][y-1]!=1){
                q.push({t+1,x,y-1}); vis[x][y-1]=1;
            }
            if(isSafe(x+1,y-1,n) && mat[x+1][y-1]==0 && vis[x+1][y-1]!=1){
                q.push({t+1,x+1,y-1}); vis[x+1][y-1]=1;
            }
            if(isSafe(x-1,y-1,n) && mat[x-1][y-1]==0 && vis[x-1][y-1]!=1){
                q.push({t+1,x-1,y-1}); vis[x-1][y-1]=1;
            }
        }
        return -1;
    }
};

int main(){
    vector<vector<int>> grid = {{0,1}, {0, 0}};
    Solution obj;
    auto answer = obj.shortestPathBinaryMatrix(grid);
    cout << "Answer: " << answer << endl;
    return 0; 
}