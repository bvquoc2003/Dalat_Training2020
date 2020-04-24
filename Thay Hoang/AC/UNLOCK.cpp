/*
#adhoc, #sorting
*/
#define taskname "UNLOCK"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long lli;
const int maxN = 1e5;
const int maxM = 1e9;
int n;
lli m, t[2 * maxN], s[2 * maxN];

inline lli ReadInt()
{
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar());
    lli x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    return x;
}

void WriteInt(lli x)
{
    if (x > 9)
        WriteInt(x / 10);
    putchar(x % 10 + '0');
}

void ReadInput()
{
    n = ReadInt(); m = ReadInt();
    for (int i = 0; i < n; ++i)
        t[i] = ReadInt() - 1;
    sort(t, t + n);
    for (int i = 0; i < n; ++i)
        t[i + n] = t[i] + m;
    s[0] = t[0];
    for (int i = 1; i < 2 * n; ++i)
        s[i] = s[i - 1] + t[i];
}

inline lli Sum(int i, int j)
{
    if (i > j) return 0;
    if (i > 0) return s[j] - s[i - 1];
    else return s[j];
}

void Solve()
{
    lli res = lli(maxN) * maxM;
    for (int i = 0; i < n; ++i)
    {
        int j = i + n - 1;
        int k = (i + j) / 2;
        lli temp = t[k] * (2 * k - i - j) - Sum(i, k - 1) + Sum(k + 1, j);
        if (temp < res) res = temp;
    }
    WriteInt(res);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".INP", "r", stdin);
    freopen(taskname".OUT", "w", stdout);
    ReadInput();
    Solve();
}
