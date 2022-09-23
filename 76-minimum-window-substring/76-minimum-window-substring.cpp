
class Solution {
public:
	
	unordered_map<char, int>mp,freq;
	bool checkCount()
	{
		for (int i = 0; i<200; i++)
		{
			if (freq[i]>mp[i])
				return false;
		}
		return true;
	}
	string minWindow(string str, string t) {
		
		for (auto c : t)
			freq[c]++;
        int req=freq.size();
		int s = 0, e = 0, mn = INT_MAX;
		string ans = "";
        int formed=0;
		while (e<str.size())
		{
			char cur = str[e];
			mp[cur]++;
            
            if(mp[cur]==freq[cur])
                formed++;
			while (s<=e && formed==req)
			{
				if ((e - s + 1)<mn)
				{
					mn = (e - s + 1);
					ans = str.substr(s, e - s + 1);
				}
				char left = str[s];
				mp[left]--;
                if(mp[left]<freq[left])
                    formed--;
				s++;
			}
			e++;
		}
		return ans;
	}
};
