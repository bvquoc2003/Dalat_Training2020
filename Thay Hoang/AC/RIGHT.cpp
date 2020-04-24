#define taskname "RIGHT"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
using lli = long long;
const int maxN = 1e5 + 1;
int n, delta, m;
int e[maxN];
lli ans[maxN];

inline int ReadInt()
{
    char c;
    while (c = getchar(), c < '0' || c > '9');
    int x = c - '0';
    while (c = getchar(), c >= '0' && c <= '9')
        x = x * 10 + c - '0';
    return x;
}

void WriteInt(lli x)
{
    if (x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}

void Solve()
{
    n = ReadInt();
    delta = ReadInt();
    m = 0;
    for (int i = 1; i <= n; ++i)
    {
        int a = ReadInt();
        int len = lower_bound(e + 1, e + m + 1, a) - e;
        e[len] = a;
        if (len > m) m = len;
        ans[i] = lli(len) * delta + a;
    }
    for (int i = 1; i <= n; ++i)
    {
        WriteInt(ans[i]);
        putchar('\n');
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".INP", "r", stdin);
    freopen(taskname".OUT", "w", stdout);
    Solve();
}
