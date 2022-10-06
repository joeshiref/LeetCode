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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* cur = head;
        int rem = 0;
        while(true)
        {
            int curVal = l1->val + l2->val + rem;
            int dig = curVal%10;
            rem = curVal/10;
            cur-> val = dig;
            l1 = l1->next;
            l2 = l2->next;
            if(l1==NULL || l2==NULL)
                break;
            cur->next = new ListNode();
            cur = cur->next;
        }
        while(l1)
        {
            int curVal = l1->val + rem;
            int dig = curVal%10;
            rem = curVal/10;
            cur->next = new ListNode(dig);
            cur = cur->next;
            l1 = l1->next;
        }
        while(l2)
        {
            int curVal = l2->val + rem;
            int dig = curVal%10;
            rem = curVal/10;
            cur->next = new ListNode(dig);
            cur = cur->next;
            l2 = l2->next;
        }
        if(rem)
            cur->next = new ListNode(1);
        return head;
    }
};