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
    void reorderList(ListNode* head) {
        vector<ListNode*>v;
        ListNode * cur=head;
        while(cur!=NULL)
        {
            v.push_back(cur);
            cur=cur->next;
        }
        
        for(int i=1,j=v.size()-1,c=1;c<v.size();c++)
        {
            
            if(c%2==1)
            {
                cout << v[j]->val << endl;
                head->next=v[j];
                j--;
            }
            else
            {
                cout << v[i]->val << endl;
                head->next=v[i];
                i++;
            }
            head=head->next;
        }
       head->next=nullptr;
    }
};