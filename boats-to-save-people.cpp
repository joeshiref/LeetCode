class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int s=0,e=people.size()-1;
        int cnt=0;
        while(s<=e)
        {
            cnt++;
            if(people[s]+people[e]<=limit)
                s++;
            e--;
        }
        return cnt;
    }
};