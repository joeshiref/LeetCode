class Solution {
public:
    
bool vis[10][10];
int dirx[4] = { 0,0,1,-1 };
int diry[4] = { 1,-1,0,0 };
int n, m;
bool valid(int i, int j, int idx, string word, vector<vector<char>>& board)
{
	return (i >= 0 && i<n && j >= 0 && j<m && !vis[i][j] && board[i][j] == word[idx]);
}
bool dfs(int i, int j, int pos, vector<vector<char>>& board, string word)
{
	vis[i][j] = true;
	if (pos > word.size())
		return false;
	if (pos==word.size())
		return true;
	bool flag = false;
	for (int f = 0; f<4; f++)
	{
		int newx = i + dirx[f];
		int newy = j + diry[f];
		if (valid(newx, newy, pos, word, board))
		{
			flag |= dfs(newx, newy, pos + 1, board, word);
		}
	}
	vis[i][j] = false;
	return flag;
}

bool exist(vector<vector<char>>& board, string word) {
	n = board.size();
	m = board[0].size();
	int cnt = 0;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			if (board[i][j] == word[0])
			{
				memset(vis, false, sizeof(vis));
				cnt += dfs(i, j, 1, board, word);
			}
		}
	}
	return cnt>0;
}
};