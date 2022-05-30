class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double>v;
        for(int i=0;i<dist.size();i++)
        {
            v.push_back(dist[i]/(double)speed[i]);
        }
        sort(v.begin(),v.end());
        int cnt=0;
        for(int i=0;i<v.size();i++)
        {
            double cur=v[i]-i;
            if(cur>0)
                cnt++;
            else
                break;
        }
        return cnt;
        
    }
};