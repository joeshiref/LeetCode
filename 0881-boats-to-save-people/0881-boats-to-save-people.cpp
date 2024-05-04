class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int cnt = 0;
        sort(people.begin(),people.end());
        int i=0,j=people.size()-1;
        while(i<=j)
        {
            int left = people[i];
            int right = people[j];
            if(left+right>limit)
                j--;
            else
            {
                i++,j--;
            }
            cnt++;
        }
        return cnt;
    }
};