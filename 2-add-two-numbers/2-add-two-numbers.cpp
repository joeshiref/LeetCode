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
        ListNode* res= new ListNode();
        ListNode* cur;
        cur=res;
        int carry=0;
        while(true)
        {
            int sumofTwoDigs = l1->val + l2->val + carry;
            if(sumofTwoDigs>9)
            {
                sumofTwoDigs = sumofTwoDigs%10;
                carry = 1;
            }
            else
                carry = 0;
            cur->val = sumofTwoDigs;
            
            l1 = l1->next;
            l2 = l2->next;
            if(l1==NULL || l2==NULL)
                break;
            cur->next = new ListNode();
            cur = cur->next;
            
        }
        while(l1)
        {
            
            cur->next = new ListNode();
            cur = cur->next;
            int sumofTwoDigs = l1->val + carry;
            if(sumofTwoDigs>9)
            {
                sumofTwoDigs = sumofTwoDigs%10;
                carry = 1;
            }
            else
                carry = 0;
            cur->val = sumofTwoDigs;
            l1 = l1->next;
            
        }
        while(l2)
        {
            cur->next = new ListNode();
            cur = cur->next;
            int sumofTwoDigs = l2->val + carry;
            if(sumofTwoDigs>9)
            {
                sumofTwoDigs = sumofTwoDigs%10;
                carry = 1;
            }
            else
                carry = 0;
            cur->val = sumofTwoDigs;
            l2 = l2->next;

        }
        if(carry)
            cur->next = new ListNode(1);
        return res;
    }
};