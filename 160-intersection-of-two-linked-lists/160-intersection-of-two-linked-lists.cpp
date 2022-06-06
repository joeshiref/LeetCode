/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * tmpa=headA;
        ListNode * tmpb=headB;
        ListNode * ans=NULL;
        map<ListNode *,int>mp;
        while(tmpa!=NULL)
        {
            mp[tmpa]++;
            tmpa=tmpa->next;            
        }
        while(tmpb !=NULL)
        {
            mp[tmpb]++;
            if(mp[tmpb]==2)
            {
                ans=tmpb;
                break;
            }
            tmpb=tmpb->next;            
        }
        return ans;
        
    }
};