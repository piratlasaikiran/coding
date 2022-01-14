#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int answer=0;
        ListNode *traverser = head;
        int power=0;
        while(traverser){
            answer = answer*2 + traverser->val;
            traverser = traverser->next;
            power++;
        }
        
        return answer;
        
    }
};

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(1);

    Solution obj;
    auto answer = obj.getDecimalValue(head);
    cout << "Answer: " << answer << endl;
    return 0;
}