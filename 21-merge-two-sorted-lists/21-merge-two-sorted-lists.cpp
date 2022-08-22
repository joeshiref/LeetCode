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
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*cur;
        if(list1==NULL && list2==NULL)
            return NULL;
		cur = new ListNode();
		ListNode* head = cur;
		while (list1 != NULL || list2 != NULL)
		{
			
			if (list2 == NULL || (list1 != NULL && list1->val <= list2->val))
			{
				cout << "Take from list 1" << endl;
				cur->val = list1->val;
				list1 = list1->next;
				//cur = cur->next;
			}
			else if (list1 == NULL || (list2 != NULL && list2->val <= list1->val))
			{
				cout << "Take from list 2" << endl;
				cur->val = list2->val;
				list2 = list2->next;
				//cur = cur->next;
			}
            if(list1 != NULL || list2 != NULL)
            {
                cur->next = new ListNode();
			    cur = cur->next;
            }
		}
		return head;
	}
};
