MOD = 1000000007

def calculate_s(t):
    s = 1
    n = len(t)
    p = [0] * (n + 1)
    e = [0] * (2 * n + 2)

    for i in range(n):
        p[i + 1] = p[i] + (1 if t[i] == '1' else -1)

    for j in range(1, n + 1):
        e[p[j - 1] + n] += j
        s = (s + e[p[j] + n] * (n - j + 1)) % MOD

    return s - 1

# Read input from standard input
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    t = input().strip()
    result = calculate_s(t)
    print(result)
