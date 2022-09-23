/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *root;
    ListNode *cur;
    void rec(ListNode* head,int stps)
    {
        if(head==NULL)
            return;
        rec(head->next,stps+1);
        cur->val = head->val;
        if(stps)
        {
            cur->next = new ListNode();
            cur = cur->next;
        }
    }
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
            return NULL;
        root = new ListNode();
        cur = root;
        rec(head,0);
        return root;
    }
};