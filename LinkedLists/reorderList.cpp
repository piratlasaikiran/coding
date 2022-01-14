#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// 1->2->3->4
class Solution {
public:

    void reorderList(ListNode* head) {
        if(!head)
            return;
        ListNode *cur = head, *last=head;
        ListNode *prevCur = nullptr, *prevLast = nullptr;
        
        prevCur = cur;
        cur = cur->next;
        while(last->next){
            prevLast = last;
            last = last->next;
        }
        
        while(cur && cur->next){
            cout << "Last: " << last->val << endl;
            prevLast->next = last->next;
            last->next = cur;
            prevCur->next = last;
            prevCur = cur;
            cur = prevCur->next;
            last = prevLast;
            last = head;
            while(last->next){
                prevLast = last;
                last = last->next;
            }
        }
    }
};

int main(){
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    // root->next->next->next->next = new ListNode(5);

    Solution obj;
    obj.reorderList(root);

    while(root){
        cout << root->val << " ";
        root = root->next;
    }
    cout << endl;
    return 0;
}