#define taskname "SHUFFLE"
#include <iostream>
#include <cstdio>
using namespace std;

const int maxN = 100000;

int a[maxN], m[maxN], b[maxN], n, k, x;

void Enter()
{
    cin >> n >> k >> x;
    for (int i = 0; i < x; i++)
        cin >> a[i] >> m[i] >> b[i];
}

int undo(int i, int m, int j, int p)
{
    int l1, l2, l3;
    if (i <= j)
    {
        l1 = i - 1;
        l2 = m;
        l3 = j - i;
    }
    else
    {
        l1 = j - 1;
        l2 = i - j;
        l3 = m;
    }
    if (p <= l1) return p;
    if (p <= l1 + l3) return p + l2;
    if (p <= l1 + l3 + l2) return p - l3;
    return p;
}

void Solve()
{
    for (int i = 1; i <= k; i++)
    {
        int p = i;
        for (int j = x - 1; j >= 0; j--)
            p = undo(a[j], m[j], b[j], p);
        cout << p << ' ';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen(taskname".INP", "r", stdin);
    freopen(taskname".OUT", "w", stdout);
    Enter();
    Solve();
}
