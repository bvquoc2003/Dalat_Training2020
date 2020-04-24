#define taskname "PRODUCT"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long lli;
const int MOD = 123456789;
const int maxN = 1e5;
int n, k, a[maxN];

inline int ReadInt()
{
    bool neg = false;
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') neg = !neg;
    int res = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        res = res * 10 + c - '0';
    return neg ? -res : res;
}

void WriteInt(int x)
{
    if (x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}

void Enter()
{
    n = ReadInt();
    k = ReadInt();
    for (int i = 0; i < n; ++i)
        a[i] = ReadInt();
}

void Solve()
{
    sort(a, a + n, [](int x, int y)
    {
        return abs(x) > abs(y);
    });
    bool neg = false;
    for (int i = 0; i < k; ++i)
    {
        if (a[i] == 0)
        {
            neg = false;
            break;
        }
        neg ^= a[i] < 0;
    }
    if (!neg) return;
    int ipos = k - 1, ineg = k - 1;
    while (ipos >= 0 && a[ipos] < 0) --ipos;
    while (ineg >= 0 && a[ineg] > 0) --ineg;
    int jpos = k, jneg = k;
    while (jpos < n && a[jpos] < 0) ++jpos;
    while (jneg < n && a[jneg] > 0) ++jneg;
    bool iposjneg = ipos >= 0 && jneg < n;
    bool inegjpos = ineg >= 0 && jpos < n;
    if (iposjneg && inegjpos)
    {
        if ((lli)a[jneg] * a[ineg] > (lli)a[ipos] * a[jpos]) //-a[jneg] * a[ipos] > a[jpos] / -a[ineg]
            swap(a[ipos], a[jneg]);
        else
            swap(a[ineg], a[jpos]);
        return;
    }
    if (iposjneg)
    {
        swap(a[ipos], a[jneg]);
        return;
    }
    if (inegjpos)
    {
        swap(a[ineg], a[jpos]);
        return;
    }
    move(&a[n - k], &a[n], &a[0]);
}

void Print()
{
    int res = 1;
    for (int i = 0; i < k; ++i)
        res = ((lli)res * a[i]) % MOD;
    res = (res + MOD) % MOD;
    WriteInt(res);
    putchar('\n');
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".INP", "r", stdin);
    freopen(taskname".OUT", "w", stdout);
    int t = ReadInt();
    while (t-- > 0)
    {
        Enter();
        Solve();
        Print();
    }
}
