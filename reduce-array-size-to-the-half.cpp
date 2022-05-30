class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int freq[100010]={};
        for(int i=0;i<arr.size();i++)
        {
            freq[arr[i]]++;
        }
        sort(freq,freq+100010);
        int cnt=0;
        int sz=arr.size();
        for(int i=100010-1;i>=0;i--)
        {
            sz-=freq[i];
            cnt++;
            if(sz<=arr.size()/2)
                break;
        }
        return cnt;
        
    }
};