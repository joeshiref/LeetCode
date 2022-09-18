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
    bool hasCycle(ListNode *head) {
        map<ListNode*,bool>mp;
        while(head!=NULL)
        {
            if(mp[head])
            {
                return true;
                break;
            }
            mp[head]=true;
            head=head->next;
        }
        return false;
    }
};