 typedef ListNode* NodePtr;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        NodePtr head = new ListNode(), curr;
        curr = head;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        if (l1) {
            curr->next = l1;
        }
        else {
            curr->next = l2;
        }

        return head->next;
    }
};