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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *s,*t,*q,*p;
    int flag=0;
    p=q=s=t=head;
    if(head==NULL)
        return head;
    if(head->next==NULL)
        return head;
    
    p=head->next;
    while(p)
    {
        t=s=head;
        while(t!=p)
        {
            if(p->val < t->val)
            {
                flag=1;
              break;
            }
            else
            {
                s=t;
                t=t->next;
            }
            
        }
        
        if(flag==1)
        {
            
                q->next=p->next;
                p->next=t;
                if(t!=head)
                {
                    s->next=p;
                    p=q->next;
                }
                else{
                    head=p;
                    p=q->next;
                }
            flag=0;
        }
        
        else
        {
        q=p;
        p=p->next;
        }
    }
    return head;
    }
};