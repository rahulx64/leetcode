class Solution
{
public:
  string minWindow(string s, string t)
  {
    map<char, int> mp;
   
    for (int i = 0; i < t.size(); i++)
    {
      char x = t[i];
      mp[x]++;
    }
    int n = s.size();
    int m = t.size();
    int l = 0;
    int r = 0;
    int si = -1;
    int mini = 1e8;
    int cnt = 0;
    while (r < n)
    {
      if (mp[s[r]] > 0)
        cnt++;
      mp[s[r]]--;
      while (cnt == m)
      {

        if (r - l + 1 < mini)
        {
          mini = r - l + 1;
          si = l;
        }
        mp[s[l]]++;
        if (mp[s[l]] > 0)
          cnt--;
        l++;
      }

      r++;
    }

    if (si == -1)
      return "";
    return s.substr(si, mini);
  }
};

