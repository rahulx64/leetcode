#include <iostream>
#include <algorithm>
using namespace std;

class math1
{
    public:
        long long fun1(long long X, long long Y, long long N)
        {
            long long c4 = N * X;
            long long g1 = N / 3;
            long long r1 = N % 3;
            long long c8 = g1 * Y + r1 * X;

            return min(c4, c8);
        }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long X, Y, N;
    cin >> X >> Y >> N;

    math1 m1;
    cout << m1.fun1(X,Y,N) << endl;
    return 0;
}