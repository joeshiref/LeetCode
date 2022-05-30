class Solution
{
public:
    vector<vector<int> >v;
    vector<int>tmp;
    int arr[10]= {1,2,3,4,5,6,7,8,9};
    void solve(int idx,int sz,int k,int rem)
    {
        if(sz==k)
        {
            if(rem==0)
            {
                v.push_back(tmp);
                //tmp.clear();
            }
            return;
        }
        if(idx>=9 || rem<0)
            return;

        if(rem-arr[idx]>=0)
        {
            tmp.push_back(arr[idx]);
            solve(idx+1,sz+1,k,rem-arr[idx]);
            tmp.pop_back();
        }
        solve(idx+1,sz,k,rem);
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        solve(0,0,k,n);
        return v;
    }
};
