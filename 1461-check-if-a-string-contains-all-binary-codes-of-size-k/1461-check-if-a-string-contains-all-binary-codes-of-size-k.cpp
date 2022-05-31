class Solution {
public:
    set<string>st;
    
    bool hasAllCodes(string s, int k) {
        if(s.size()<k)
            return false;
        int cnt=1<<k;
        for(int i=0;i<=s.length()-k;i++)
        {
            string str=s.substr(i,k);
            st.insert(str);
        }
        
        return (st.size()==cnt);
    }
    
};