class Solution {
public:
    int divisorSubstrings(int num, int k) {
        stringstream ss;
        ss<<num;
        string str;
        ss>>str;
        int cnt=0;
        for(int i=0;i<str.size();i++)
        {
            string tmp="";
            for(int j=i;j<i+k && j<str.size();j++)
                tmp+=str[j];
            int x;
            x=stoi(tmp);
            if( x!=0 && num%x==0 && tmp.size()==k)
            {
                cnt++;
            }
        }
        return cnt;
        
    }
};