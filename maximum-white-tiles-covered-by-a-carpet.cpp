
class Solution
{
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen)
    {
        sort(tiles.begin(), tiles.end());
        long long res = 0;
        long long cur = 0;
        for(int i = 0, j = 0; i < tiles.size(); ++i)
        {
            cur += tiles[i][1] - tiles[i][0] + 1;
            while(tiles[j][1] < tiles[i][1] - carpetLen)
            {
                cur -= tiles[j][1] - tiles[j][0] + 1;
                ++j;
            }
            long long v = cur - max(0, (tiles[i][1] - carpetLen + 1) - tiles[j][0]);
            res = max(res, v);
        }
        return res;
    }
};