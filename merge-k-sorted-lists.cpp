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
   
ListNode* mergeKLists(vector<ListNode*>& lists)
{
    priority_queue<int>pq;
    for(int i=0; i<lists.size(); i++)
    {
        ListNode *head = lists[i];
        while(head!=NULL)
        {
            pq.push(head->val*-1);
            head=head->next;
        }
    }
    if(!pq.size())
        return NULL;
    ListNode* head;
    ListNode* cur= new ListNode(pq.top()*-1);
    pq.pop();
    head=cur;
    while(!pq.empty())
    {
        int val=pq.top()*-1;
        cur->next = new ListNode(val);
        int tmp=cur->val;
        cur=cur->next;
        pq.pop();
    }
    return head;

}
};