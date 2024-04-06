class Solution {
public:
    string makeGood(string s) {
        string ans ="";
        deque<char>dq;
        for(auto c:s)
        {
            if(dq.size())
            {
                if((isupper(dq.back()) && islower(c) && tolower(dq.back()) == tolower(c)) ||
                  isupper(c) && islower(dq.back()) && tolower(dq.back()) == tolower(c))
                {
                    dq.pop_back();
                    continue;
                }
            }
            dq.push_back(c);
        }
        for(auto ca:dq)
            ans+=ca;
        return ans;
    }
};