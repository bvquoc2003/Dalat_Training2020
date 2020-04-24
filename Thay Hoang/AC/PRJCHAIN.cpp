/*
#Johnson rule;
*/
#define taskname "PRJCHAIN"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long lli;
const int maxN = 1e5 + 1;
int n, a[maxN], b[maxN], id[maxN];

inline int ReadInt()
{
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar() );
    int res = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar() )
        res = res * 10 + c - '0';
    return res;
}

void WriteInt(lli x)
{
    if (x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}

void Enter()
{
    n = ReadInt();
    for (int i = 1; i <= n; ++i) a[i] = ReadInt();
    for (int i = 1; i <= n; ++i) b[i] = ReadInt();
    for (int i = 1; i <= n; ++i) id[i] = i;
}

void Print()
{
    lli cap = 0, initcap = 0;
    for (int i = 1; i <= n; ++i)
    {
        int j = id[i];
        cap -= a[j];
        if (cap < 0)
        {
            initcap -= cap;
            cap = 0;
        }
        cap += b[j];
    }
    WriteInt(initcap);
    putchar('\n');
    for (int i = 1; i <= n; ++i, putchar(' '))
        WriteInt(id[i]);
}

int main()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    freopen (taskname".inp", "r", stdin);
    freopen (taskname".out", "w", stdout);
    Enter();
    sort (id + 1, id + n + 1, [] (int i, int j)
    {
        return min (a[i], b[j]) < min (a[j], b[i]);
    });
    Print();
}
