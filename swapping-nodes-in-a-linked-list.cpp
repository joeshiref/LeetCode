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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* cur= head;
        ListNode* left= head;
        ListNode* right= head;
        int cnt=1;
        while(cur!=NULL)
        {
            if(cnt<k)
                left=left->next;
            else if(cnt>k)
                right=right->next;
            cnt++;
            cur=cur->next;
        }
        swap(left->val,right->val);
        return head;
    }
};