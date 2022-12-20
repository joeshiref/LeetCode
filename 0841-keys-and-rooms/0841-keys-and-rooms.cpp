class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int>que;
        for(auto key:rooms[0])
            que.push(key);
        vector<bool>vis(rooms.size(),false);
        vis[0]=true;
        while(!que.empty())
        {
            int cur = que.front();
            vis[cur]=true;
            que.pop();
            for(auto room:rooms[cur])
            {
                if(!vis[room])
                    que.push(room);
            }
        }
        int res = true;
        for(auto flag:vis)
            res&=flag;
        return res;
    }
};