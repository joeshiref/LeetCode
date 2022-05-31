class Solution {
public:
    unordered_map<string,bool>mp;
    
    bool hasAllCodes(string s, int k) {
        if(s.size()<k)
            return false;
        int cnt=1<<k;
        for(int i=0;i<=s.length()-k;i++)
        {
            string str=s.substr(i,k);
            mp[str]=true;
        }
        
        return (mp.size()==cnt);
    }
    
};