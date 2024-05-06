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
    ListNode* removeNodes(ListNode* head) {
        ListNode * cur = head;
        vector<int>vec;
        while(cur)
        {
            vec.push_back(cur->val);
            cur = cur->next;
        }
        stack<int>st;
        st.push(vec[0]);
        
        for(int i=1;i<vec.size();i++)
        {
            if(st.empty())
            {
                st.push(vec[i]);
                continue;
            }
            while (st.empty() == false && st.top() < vec[i]) {
                //cout << s.top() << " --> " << arr[i] << endl;
                st.pop();
            }
            st.push(vec[i]);
        }
        vector<int>res;
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        ListNode* headd = nullptr;
        ListNode* tail = nullptr;
        for(int i=0;i<res.size();i++)
        {
            ListNode* newNode = new ListNode(res[i]);

            if (!headd) {
                headd = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        
        return headd;
        
        
    }
};