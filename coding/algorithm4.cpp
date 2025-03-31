#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int n, vector<int> r, vector<int> h)
{
     const int mod = 1e9 + 7;
     long long prev = -1;
     long long maxi = 0;
     long long sum = 0;

     for (int i = 0; i < n; i++)
     {
          long long vol = (1LL * r[i] * r[i] % mod) * h[i] % mod;
          if (vol > prev)
          {
               prev = vol;
               sum = (sum + vol) % mod;
          }
          else
          {
               maxi = max(maxi, sum);
               sum = vol;
               prev = vol;
          }
     }
     sum %= mod;
     maxi = max(maxi, sum);

     return int(maxi);
}

int main()
{
     int n;
     cout << "Enter number of elements: ";
     cin >> n;

     vector<int> r(n), h(n);

     cout << "Enter values for r: ";
     for (int i = 0; i < n; i++)
     {
          cin >> r[i];
     }

     cout << "Enter values for h: ";
     for (int i = 0; i < n; i++)
     {
          cin >> h[i];
     }

     int result = solve(n, r, h);
     cout << "The result is: " << result << endl;

     return 0;
}
