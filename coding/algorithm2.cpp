#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
  // Your code here
  int n;
  cin >> n;
  vector<int> val(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> val[i];
  vector<int> path[n + 1];
  for (int i = 1; i <= n; i++)
  {
    int x, y;
    cin >> x >> y;
    path[x].push_back(y);
    path[y].push_back(x);
  }

  
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}