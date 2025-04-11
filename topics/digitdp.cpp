// count of number between l and r which have sum of digit = x   1<=l<=r<=10^18     let x=180 example thee might be many varient solve on leetcode and revise it 
// dp(n,x) no of n digit number with sum=x
// dp(n,x)=sigma dp(n-1,x-i) 0<=i<=9
// in some dp version there might be some topic called as tight constraints which help us get number of digit between 0 to 45678  then another dp variable of size 2 is included  
// dp(n,x,tight)
//5231 consider example  dp(n,x,1)=dp(n-1,x,0)+dp(n-1,x-1,0)+dp(n-1,x-2,0)+dp(n-1,x-3,0)+dp(n-1,x-4,0)+dp(n-1,x-5,1)



#include <bits/stdc++.h>
using namespace std;

int dp[20][2][100]; // pos, tight, sum

string num;
int K;

int digitDP(int pos, bool tight, int sum)
{
     if (pos == num.size())
          return sum % K == 0 ? 1 : 0;

     if (dp[pos][tight][sum] != -1)
          return dp[pos][tight][sum];

     int limit = tight ? num[pos] - '0' : 9;
     int res = 0;

     for (int d = 0; d <= limit; ++d)
     {
          bool next_tight = tight && (d == limit);
          res += digitDP(pos + 1, next_tight, sum + d);
     }

     return dp[pos][tight][sum] = res;
}

int solve(string N, int k)
{
     num = N;
     K = k;
     memset(dp, -1, sizeof(dp));
     return digitDP(0, 1, 0);
}

int main()
{
     string N;
     int K;
     cout << "Enter number N: ";
     cin >> N;
     cout << "Enter divisor K: ";
     cin >> K;

     int ans = solve(N, K);
     cout << "Count of numbers <= N with digit sum divisible by K: " << ans << endl;
}
