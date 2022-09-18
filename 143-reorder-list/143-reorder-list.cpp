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
        stack<ListNode*>st;
        int sz;
        ListNode* ptr = head;
        while(ptr!=NULL)
        {
            st.push(ptr);
            ptr = ptr->next;
        }
        sz=st.size();
        ptr = head;
        for(int i=0;i<sz/2;i++)
        {
            ListNode* cur = st.top();
            st.pop();
            cur->next = ptr->next;
            ptr->next=cur;
            ptr = ptr->next->next;
        }
        ptr->next = NULL;
    }
};