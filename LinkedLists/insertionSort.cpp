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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(INT_MIN);
        ListNode* traverser = dummy;
        while(head){
            ListNode *next = head->next;
            traverser = dummy;
            while(traverser->next && traverser->next->val < head->val){
                traverser = traverser->next;
            }
            head->next = traverser->next;
            traverser->next = head;
            head = next;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};

/// [4,19,14,5,-3,1,8,5,11,15]

int main(){
    ListNode *head = new ListNode(4);
    head->next = new ListNode(19);
    head->next->next = new ListNode(14);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(-3);
    // head->next->next->next->next->next = new ListNode(1);
    // head->next->next->next->next->next->next = new ListNode(8);
    // head->next->next->next->next->next->next->next = new ListNode(5);
    // head->next->next->next->next->next->next->next->next = new ListNode(11);
    // head->next->next->next->next->next->next->next->next->next = new ListNode(15);

    Solution obj;
    auto answer = obj.insertionSortList(head);

    while(answer) {
        cout << answer->val << " ";
        answer = answer->next;
    }
    cout << endl;

    return 0;
}