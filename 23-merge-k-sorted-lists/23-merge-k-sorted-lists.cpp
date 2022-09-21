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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size())
            return NULL;
        vector<int>vec;
        for(int i=0;i<lists.size();i++)
        {
            ListNode*node=lists[i];
            while(node)
            {
                vec.push_back(node->val);
                node=node->next;
            }
        }
        sort(vec.begin(),vec.end());
        ListNode* head;
        ListNode* cur;
        
        for(int i=0;i<vec.size();i++)
        {
            if(!i)
            {
                head = new ListNode();
                cur=head;
            }
            cur->val = vec[i];
            if(i<vec.size()-1)
            {
                cur->next = new ListNode();
                cur = cur->next;
            }
        }
        
        
        
        return head;
    }
};