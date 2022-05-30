class Solution {
public:
    bool found = false;
    void help(int pos, vector<int>& matchsticks, int one, int two, int three, int four, long long &sum)
    {
        if(found)
            return;
        
        if(pos == matchsticks.size())
        {
            if(one == two and two == three and three == four)
                found = true;
            
            return;
        }
        
        if(one > sum/4 or two > sum/4 or three > sum/4 or four > sum/4)
            return;
            
        if(matchsticks.size() - pos >= 4)
            help(pos+1, matchsticks, one + matchsticks[pos], two, three, four, sum);
        
        if(matchsticks.size() - pos >= 3)
            help(pos+1, matchsticks, one, two + matchsticks[pos], three, four, sum);
        
        if(matchsticks.size() - pos >= 2)
            help(pos+1, matchsticks, one, two, three + matchsticks[pos], four, sum);
        
        if(matchsticks.size() - pos >= 1)
            help(pos+1, matchsticks, one, two, three, four + matchsticks[pos], sum);
    }
    
    bool makesquare(vector<int>& matchsticks) 
    {    
        long long sum=0;
        for(auto i:matchsticks)
            sum += i;

        if (matchsticks.size() < 4 or sum % 4) 
            return false;
        
        // Imp otherwise might get a TLE even after passing all testcases
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());

        if(matchsticks[0]> (sum/4))
            return false;
        
        help(0, matchsticks, 0, 0, 0, 0, sum);
        return found;
    }
};