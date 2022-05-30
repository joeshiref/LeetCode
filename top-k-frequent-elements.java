

class pair implements Comparable<pair>
{
    int x,y;

    @Override
    public int compareTo(pair o) {
        if(x>o.x){
            return 1;
        }else if(x<o.x){
            return -1;
        }else{
            return 0;
        }
    }
}

class Solution {
    public int[] topKFrequent(int[] nums, int k) {
                HashMap<Integer, Integer> mp = new HashMap<Integer,Integer>();

        for(int i=0;i<nums.length;i++)
        {
            Integer x=nums[i];
            int count = mp.containsKey(x) ? mp.get(x) : 0;
            mp.put(x,count+1);
        }
        PriorityQueue<pair> pq = new PriorityQueue<pair>();
        for(Map.Entry mpElement: mp.entrySet())
        {
            pair tmp = new pair();
            tmp.x=(int)mpElement.getValue()*-1;
            tmp.y=(int)mpElement.getKey();
            pq.add(tmp);
        }
        int idx=0;
        int []res= new int[k];
        while(!pq.isEmpty()&&(k--!=0))
        {
            res[idx++]=pq.peek().y;       
            pq.remove();
        }
        return res;
        
    }
}