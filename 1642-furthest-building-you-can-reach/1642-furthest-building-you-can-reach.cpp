
class Solution
{
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders)
    {
        priority_queue<int>pq;
        int i=1;
        for(; i<heights.size(); i++)
        {
            if(heights[i-1]-heights[i]<0)
            {
                int absValue=-(heights[i-1]-heights[i]);
                if(bricks>=absValue)
                {
                    bricks-=absValue;
                    pq.push(absValue);
                }
                else
                {
                    if(ladders>0)
                    {
                        if(pq.size() && absValue<pq.top())
                        {
                            bricks+=pq.top();
                            bricks-=absValue;
                            pq.pop();
                            pq.push(absValue);
                        }
                        ladders--;
                    }
                    else
                        break;

                }


            }
        }

        return i-1;
    }
};
