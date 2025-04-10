class Solution
{
public:
     int solve(int r1, int c1, int r2, int c2, vector<vector<int>> &grid, int dp[51][51][51][51])
     {

          int n = grid.size(), m = grid[0].size();

          if(r1>=n || c1>=m || r2>=n || c2>=m || grid[r1][c1]==-1 || grid[r2][c2]==-1)
          {
               return INT_MIN;
          }
          
          if(r1==n-1 && c1==m-1 && r2==n-1 && c2==m-1)
          {
               return grid[r1][c1];
          }

          if(dp[r1][c1][r2][c2] != -1)
          {
               return dp[r1][c1][r2][c2];
          }

          int cherries = 0;
          if (r1 == r2)
          {
               cherries += grid[r1][c1];
          }
          else
          {
               cherries += grid[r1][c1] + grid[r2][c2];
          }
          int f1=solve(r1, c1 + 1, r2, c2 + 1, grid, dp);
          int f2=solve(r1, c1 + 1, r2 + 1, c2, grid, dp);
          int f3=solve(r1 + 1, c1, r2, c2 + 1, grid, dp);
          int f4=solve(r1 + 1, c1, r2 + 1, c2, grid, dp);
          int ans = max({f1, f2, f3, f4});

          return dp[r1][c1][r2][c2]= ans;
     }

     int cherryPickup(vector<vector<int>> &grid)
     {
          int dp[51][51][51][51];
          memset(dp, -1, sizeof(dp));
          solve(0, 0, 0, 0, grid, dp);
     }
};