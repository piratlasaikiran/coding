#include <bits/stdc++.h>
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* traverser = NULL, *originalHead=head;
        while(head != NULL){
            if(head->val == val && traverser){
                traverser->next = head->next;
                head = traverser->next;

            }
            else if(head->val == val && !traverser){
                head = head->next;
                originalHead = head;

            }
            else{
                traverser = head;
                head = head->next;
            }
            
        }
    return originalHead;    
    }
};
int main(){
    ListNode* head = new ListNode(6);
    // head->next = new ListNode(5);
    // head->next->next = new ListNode(6);
    // head->next->next->next = new ListNode(6);
    // head->next->next->next->next = new ListNode(6);
    // head->next->next->next->next->next = new ListNode(6);
    // head->next->next->next->next->next->next = new ListNode(6);

    Solution obj;
    auto answer = obj.removeElements(head, 6);

    while(answer != NULL){
        cout << answer->val;
        answer = answer->next;
    }
    cout << endl;
}