class Solution {
public:
    
int countSoFar[200];
int freqOfTarget[200];
bool check()
{
	bool flag = true;
	for (int j = 0; j<200; j++)
	{
		if (freqOfTarget[j]>countSoFar[j])
			flag = false;
	}
	return flag;

}
string minWindow(string s, string t)
{

	for (auto c : t)
		freqOfTarget[c]++;

	int start = 0, end = 0, mn = INT_MAX;
	string ans = "";
	while (start <= end && end<s.size())
	{
		countSoFar[s[end]]++;
		bool flag = check();
		if (flag)
		{
			while (check())
			{
				int len = end - start + 1;
				if (len<mn)
				{
					mn = len;
					ans = s.substr(start, len);
				}
				countSoFar[s[start]]--;
				start++;
			}
		}
		end++;
	}
	return ans;
}

};