class Solution {
public:
    int ans=0;

int start_row=-1;
int start_col=-1;

int uniquePathsIII(vector<vector<int>>& arr) 
{    
    int count=0;
    for(int i=0;i<arr.size();i++)
    {
    	for(int j=0;j<arr[i].size();j++)
    	{
    		if(arr[i][j]==0)
    		{
    			count++;
			}
    		else if(arr[i][j]==1)
    		{
    			count++;
    			start_row=i;
    			start_col=j;
			}
			else if(arr[i][j]==2)
			{
				count++;
			}
		}
	}
    
    int i=start_row;
    int j=start_col;
    
    fun(arr,i,j,count);
    
	return ans;
}
void fun(vector<vector<int>>&arr,int row,int col,int count)
{
	if(row<0 or row>=arr.size() or col<0 or col>=arr[0].size())  //out of the bound
	{
		return;
	}
	if(arr[row][col]==-1)   //the curr cell is blocked
	{
		return;
	}
	
	if(arr[row][col]==2 and (count-1)==0)
	{
	   ans++;
       return;	
    }
    
    if(arr[row][col]==2 and (count-1)!=0)
    {
   	   return;
	}
	 
    arr[row][col]=-1;
	
	fun(arr,row-1,col,count-1);  //up
	fun(arr,row+1,col,count-1);  //down
	fun(arr,row,col-1,count-1);  //left
	fun(arr,row,col+1,count-1);  //right
	
	arr[row][col]=1;   //backtracking
	
}
};