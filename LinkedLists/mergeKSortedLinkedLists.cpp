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

    ListNode* mergeTwoLists(ListNode* l1, ListNode*l2){
        if(l1 == nullptr){
            return l2;
        }
        if(l2 == nullptr){
            return l1;
        }
        ListNode* dummyNode = new ListNode(-1);
        ListNode* prevNode = dummyNode;

        while(l1 != nullptr && l2 != nullptr){
            if(l1->val < l2->val){
                prevNode->next = l1;
                l1 = l1->next;
            }
            else{
                prevNode->next = l2;
                l2 = l2->next;
            }
            prevNode = prevNode->next;
        }
        prevNode->next = (l1 != nullptr) ? l1 : l2;
        return dummyNode->next;
    }

    ListNode* mergeKListsHelper(vector<ListNode*>& lists, int start, int end){
        if(start > end){
            return nullptr;
        }
        if(start == end){
            return lists[start];
        }
        int mid = (start+end)/2;
        ListNode* l1 = mergeKListsHelper(lists, start, mid);
        ListNode* l2 = mergeKListsHelper(lists, mid+1, end);

        return mergeTwoLists(l1, l2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0){
            return nullptr;
        }
        return mergeKListsHelper(lists, 0, n-1);
    }
};

int main(){
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(7);

    vector<ListNode*> nodes = {l1, l2};
    Solution obj;
    auto answer = obj.mergeKLists(nodes);
    cout << "Answer: " ;
    while(answer != nullptr){
        cout << answer->val << " ";
        answer = answer->next;
    }
    cout << endl;
    return 0;
}