#include <bits/stdc++.h>
using namespace std;

int minCandlesToBuy(int N, int K, vector<int> &candles)
{
    unordered_map<int, int> freq;
    int count = 0, left = 0, minLength = N + 1;

    for (int right = 0; right < N; right++)
    {
        if (candles[right] <= K)
        {
            if (freq[candles[right]] == 0)
                count++;
            freq[candles[right]]++;
        }

        while (count == K)
        {
            minLength = min(minLength, right - left + 1);
            if (candles[left] <= K)
            {
                freq[candles[left]]--;
                if (freq[candles[left]] == 0)
                    count--;
            }
            left++;
        }
    }

    return (minLength == N + 1) ? -1 : minLength;
}

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> candles(N);
    for (int i = 0; i < N; i++)
        cin >> candles[i];

    cout << minCandlesToBuy(N, K, candles) << endl;
    return 0;
}