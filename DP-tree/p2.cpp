#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> tree[MAXN];
int dp[MAXN][2]; // dp[u][0] -> u not matched, dp[u][1] -> u matched

void dfs(int u, int parent)
{
     dp[u][0] = 0; // Initialize when u is not matched
     dp[u][1] = 0; // Initialize when u is matched

     for (int v : tree[u])
     {
          if (v == parent)
               continue; // Skip the parent node
          dfs(v, u);

          // If u is not matched, take the max of child being matched or not
          dp[u][0] += max(dp[v][0], dp[v][1]);
     }

     // If u is matched, try matching u with one of its children
     for (int v : tree[u])
     {
          if (v == parent)
               continue;

          // Match u with v and take max for other children
          dp[u][1] = max(dp[u][1], 1 + dp[v][0] + (dp[u][0] - max(dp[v][0], dp[v][1])));
     }
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);

     int n;
     cin >> n;

     for (int i = 1; i < n; i++)
     {
          int u, v;
          cin >> u >> v;
          tree[u].push_back(v);
          tree[v].push_back(u);
     }

     dfs(1, -1); // Root the tree at node 1

     cout << max(dp[1][0], dp[1][1]) << "\n"; // Maximum matching edges
     return 0;
}
