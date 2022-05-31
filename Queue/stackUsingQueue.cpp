#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:

    queue<int> stackedQueue;

    MyStack() {
        
    }
    
    void push(int x) {
        int n = stackedQueue.size();
        stackedQueue.push(x);
        for(int i=0; i<n; i++){
            int frontElement = stackedQueue.front();
            stackedQueue.pop();
            stackedQueue.push(frontElement);
        }
    }
    
    int pop() {
        int frontElement = stackedQueue.front();
        stackedQueue.pop();
        return frontElement;
    }
    
    int top() {
        int frontElement = stackedQueue.front();
        return frontElement;
    }
    
    bool empty() {
        return stackedQueue.size()==0;
    }
};