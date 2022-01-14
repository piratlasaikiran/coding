#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    
    bool hasCycleHelper(vector<vector<int>>& preReqDetails,vector<int>& graphColour,int courseID)
    {
        if(graphColour[courseID]==1)
            return true;
        if(graphColour[courseID]==2)
            return false;
        
        graphColour[courseID]=1;
        vector<int> neighbours = preReqDetails[courseID];
        int neighboursSize = neighbours.size();
        for(int i=0; i<neighboursSize; i++){
            if(hasCycleHelper(preReqDetails, graphColour, neighbours[i])){
                return true;
            }
        }
        
        graphColour[courseID]=2;
        return false;
    }
    
    bool hasCycle(vector<vector<int>> preReqDetails, int numCourses)
    {
        vector<int> graphColour(numCourses,0);
        for(int i=0;i<numCourses;i++)
            if(!graphColour[i])
                if(hasCycleHelper(preReqDetails, graphColour, i))
                    return true;
        return false;
    }
    
    void findOrderHelper(vector<vector<int>>& preReqDetails,int courseID,vector<bool>& visitedSubjects,stack<int>& subjectsInOrder)
    {
        visitedSubjects[courseID] = true;
        vector<int> coursesReq = preReqDetails[courseID];
        int preReqCount = coursesReq.size();
        for(int i=0;i<preReqCount;i++)
            if(!visitedSubjects[coursesReq[i]])
                findOrderHelper(preReqDetails, coursesReq[i], visitedSubjects, subjectsInOrder);
        
        subjectsInOrder.push(courseID);
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<vector<int>> preReqDetails(numCourses);
        for(int i=0;i<n;++i)
            preReqDetails[prerequisites[i][1]].push_back(prerequisites[i][0]);
        
        vector<int> ans;
        if(hasCycle(preReqDetails,numCourses))
            return ans;        
        
        stack<int> subjectsInOrder;
        vector<bool> visitedSubjects(numCourses,false);
        
        for(int i=0;i<numCourses;i++)
            if(!visitedSubjects[i])
                findOrderHelper(preReqDetails,i,visitedSubjects,subjectsInOrder);
        
        while(!subjectsInOrder.empty())
        {
            ans.push_back(subjectsInOrder.top());
            subjectsInOrder.pop();
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> prerequisites = {{1,0},{0,1}};
    Solution obj;
    auto answer = obj.findOrder(2, prerequisites);
    cout << "Answer: ";
    for(auto i:answer)
        cout << i << " ";
    cout << endl;
    return 0;
}