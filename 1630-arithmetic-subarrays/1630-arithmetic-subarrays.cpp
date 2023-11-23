class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        int len = l.size();
        vector<bool>ans;
        for(int i=0;i<len;i++)
        {
            vector<int>vec(nums.begin()+l[i], nums.begin()+r[i]+1);
            sort(vec.begin(),vec.end());
            int diff = 0;
            bool flag=true;
            for(int j=0;j<vec.size()-1;j++)
            {
                if(!j)
                    diff = vec[j+1] - vec[j];
                else
                {
                    if ( (vec[j+1] - vec[j] ) != diff)
                    {
                        flag=false;
                        break;
                    }
                }
            }
            ans.push_back(flag);
        }
        return ans;
        
    }
};