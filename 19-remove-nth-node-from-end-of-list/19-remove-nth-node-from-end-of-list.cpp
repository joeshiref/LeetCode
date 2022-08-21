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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * cur = head;
        int len=0;
        while(cur!=NULL)
        {
            len++;
            cur=cur->next;
        }
        int neededNode = len-n;
        if(neededNode==0)
            return head->next;
        int cnt=1;
        cur = head;
        while(cur!=NULL)
        {
            if(cnt==neededNode)
                cur->next=cur->next->next;
            cnt++;
            cur=cur->next;
        }
        return head;
    }
};