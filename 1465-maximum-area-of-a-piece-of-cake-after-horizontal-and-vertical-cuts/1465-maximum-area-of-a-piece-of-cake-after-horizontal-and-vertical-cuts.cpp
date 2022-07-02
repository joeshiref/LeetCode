class Solution {
public:
    long long max(long long a, long long b)
    {
        return a>b?a:b;
    }
    long long maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(h);
        sort(horizontalCuts.begin(),horizontalCuts.end());
        verticalCuts.push_back(w);
        sort(verticalCuts.begin(),verticalCuts.end());
        int horizontalPosition=0;
        long long maximumHeight=0;
        for(int i=0;i<horizontalCuts.size();i++)
        {
            maximumHeight=max(maximumHeight,horizontalCuts[i]-horizontalPosition);
            horizontalPosition=horizontalCuts[i];
        }
        //cout << "Max Height: " << maximumHeight << endl;
        maximumHeight=maximumHeight%1000000007;
        int vertialPosition=0;
        long long maximumWidth=0;
        for(int i=0;i<verticalCuts.size();i++)
        {
            maximumWidth=max(maximumWidth,verticalCuts[i]-vertialPosition);
            vertialPosition=verticalCuts[i];
        }
        //cout << "Max Width: " << maximumWidth << endl;
        maximumWidth=maximumWidth%1000000007;
        return (maximumWidth*maximumHeight)%1000000007;
    }
};