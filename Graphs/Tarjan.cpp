// Resource: https://www.youtube.com/watch?v=ZeDNSeilf-Y
#include<bits/stdc++.h>
using namespace std;

class Tarjan{
    public:
    int time=0;
    vector<vector<int>> SSC;

    void DFS(unordered_map<int, vector<int>> graph, vector<int>& low, vector<int>& discovery, vector<bool>& inStack, stack<int>& ver_stack, int i){
        discovery[i] = time;
        low[i] = i;
        time++;
        inStack[i] = true;
        ver_stack.push(i);

        for(int v:graph[i]){
            if(discovery[v] == -1){
                DFS(graph, low, discovery, inStack, ver_stack, v);
                low[i] = min(low[i], low[v]);
            }
            else if(inStack[i]){
                low[i] = min(low[i], discovery[v]);
            }
        }

        if(low[i] == discovery[i]){
            vector<int> ssc_component;
            while(ver_stack.top() != i){
                ssc_component.push_back(ver_stack.top());
                inStack[ver_stack.top()] = false;
                ver_stack.pop();                
            }
            ssc_component.push_back(ver_stack.top());
            SSC.push_back(ssc_component);
            inStack[ver_stack.top()] = false;
            ver_stack.pop();
        }
    }

    void find_SSC(unordered_map<int, vector<int>> graph, int vertices){
        vector<int> low(vertices, -1);
        vector<int> discovery(vertices, -1);
        vector<bool> inStack(vertices, false);
        stack<int> ver_stack;
        for(int i=0; i<vertices; i++){
            if(discovery[i] == -1)
                DFS(graph, low, discovery, inStack, ver_stack, i);
        }
            
        for(auto i:SSC){
            cout<<"SS Component: " ;
            for(auto j:i)
                cout << j << " ";
            cout<<endl;
        }  
    }
    
};

int main(){
    unordered_map<int, vector<int>> graph;
    int vertices = 7;
    graph[0].push_back(1);
	graph[1].push_back(2);
	graph[1].push_back(3);
	graph[3].push_back(4);
	graph[4].push_back(0);
	graph[4].push_back(5);
	graph[4].push_back(6);
	graph[5].push_back(6);
	graph[6].push_back(5);

    Tarjan obj;    
    obj.find_SSC(graph, vertices);
 

    return 0;
}