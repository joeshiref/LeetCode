class Solution {
public:
    string frequencySort(string s) {
        int freq[128];
        memset(freq,false,sizeof(freq));
        for(auto c:s)
            freq[c]++;
        priority_queue<pair<int,char> >pq;
        for(int i=0;i<128;i++)
        {
            if(freq[i])
                pq.push({freq[i],i});
        }
        string ans="";
        while(!pq.empty())
        {
            pair<int,char>cur=pq.top();
            while(cur.first)
            {
                ans+=cur.second;
                cur.first--;
            }
            pq.pop();
        }
        return ans;
    }
};