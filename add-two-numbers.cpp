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

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {

        ListNode *l3;
        ListNode *cur;
        cur=new ListNode();
        l3=cur;
        int rem=0,cnt=0;
        while(true)
        {
            int tmpRes=l1->val+l2->val+rem;
            int val=tmpRes%10;
            rem=tmpRes/10;
            //cur=new ListNode(val);
            cur->val=val;
            l1=l1->next;
            l2=l2->next;
            if(l1==NULL || l2==NULL)
                break;
            cur->next=new ListNode();
            cur=cur->next;
        }
        while(l1!=NULL)
        {
            cur->next=new ListNode();
            cur=cur->next;
            int tmpRes=l1->val+rem;
            int val=tmpRes%10;
            rem=tmpRes/10;
            cur->val=val;
            l1=l1->next;

        }
        while(l2!=NULL)
        {
            cur->next=new ListNode();
            cur=cur->next;
            int tmpRes=l2->val+rem;
            int val=tmpRes%10;
            rem=tmpRes/10;
            cur->val=val;
            l2=l2->next;
        }
        if(rem)
        {
            cur->next=new ListNode();
            cur=cur->next;
            cur->val=rem;

        }

        return l3;

    }
};
