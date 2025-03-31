#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
vector<bool> isprime(4e4 + 1, 1);
vector<int> primes{};
void sieve()
{
     for (int i = 2; i <= 4e4; i++)
     {
          if (isprime[i] && (long long)i * i <= 4e4)
          {
               for (int j = i * i; j <= 4e4; j += i)
               {
                    isprime[j] = false;
               }
          }
     }
     for (int i = 2; i <= 4e4; i++)
     {
          if (isprime[i])
               primes.push_back(i);
     }
}
signed main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     sieve();
     int t;
     cin >> t;
     while (t--)
     {
          int p, q;
          cin >> p >> q;
          if (p % q != 0)
          {
               cout << p << '\n';
               continue;
          }
          vi pr;
          int q2 = q;
          for (auto pp : primes)
          {
               if (pp > q2)
                    break;
               if (q2 % pp == 0)
                    pr.pb(pp);
               while (q2 % pp == 0)
                    q2 /= pp;
          }
          if (q2 > 1)
               pr.pb(q2);
          int x = 1;
          for (auto pp : pr)
          {
               int x1 = p;
               while (x1 % q == 0 && x1 > 0)
                    x1 /= pp;
               x = max(x1, x);
          }
          cout << x << '\n';
     }
     return 0;
}