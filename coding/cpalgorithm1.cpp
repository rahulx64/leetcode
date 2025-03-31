#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
     // Your code here
     int n;
     cin >> n;

     unordered_map<int, pair<int, int>> mp;
     for (int i = 0; i < n; i++)
     {
          int x, y;
          cin >> x >> y;
          mp[i] = {x, y};
     }

     vector<int> path[n];
     for (int i = 0; i < n - 1; i++)
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