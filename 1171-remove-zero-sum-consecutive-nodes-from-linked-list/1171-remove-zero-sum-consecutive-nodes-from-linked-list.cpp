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
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int>vec;
        ListNode * ptr = head;
        while(ptr)
        {
            vec.push_back(ptr->val);
            ptr = ptr->next;
        }
        
        vector<int>prefixSum(vec.size()+1,0);
        for(int i=0;i<vec.size();i++)
        {
            prefixSum[i+1]=prefixSum[i]+vec[i];
        }
        
        
        unordered_map<int,int>mp;
        for(int i=0;i<prefixSum.size();i++)
        {
            int cur = prefixSum[i];
            // element cur found in the hash map
            if(mp.find(cur)!=mp.end())
            {
                int idx = mp[cur];
                for(int j=idx;j<i;j++)
                {
                    vec[j]=INT_MAX;
                    mp.erase(prefixSum[j]);
                }
            }
            
            mp[cur]=i;
        }
        vector<int>res;
        for(auto num:vec)
        {
            if(num!=INT_MAX)
                res.push_back(num);
        }
        if(!res.size())
            return NULL;
        ListNode * front = new ListNode(res[0]);
        ListNode * cur = front;
        for(int i=1;i<res.size();i++)
        {
            cur->next = new ListNode(res[i]);
            cur = cur->next;
        }
        
        return front;
    }
};