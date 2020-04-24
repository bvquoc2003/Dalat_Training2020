/*
#dynamic programming, #knuth optimization
*/
#define taskname "OPTBST"
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long lli;
const int maxN = 2e3 + 1;
const int maxC = 1e9;
const lli infty = lli(maxN) * maxN * maxC;
int n, c[maxN];
lli sumc[maxN];
lli f[maxN][maxN];
int r[maxN][maxN];

void Enter()
{
    cin >> n;
    sumc[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> c[i];
        sumc[i] = sumc[i - 1] + c[i];
    }
}

inline lli freq(int i, int j)
{
    return sumc[j] - sumc[i - 1];
}

void Init()
{
    for (int i = 1; i <= n; ++i)
    {
        f[i][i - 1] = 0;
        f[i][i] = c[i];
        r[i][i] = i;
    }
}

inline bool Minimize(lli& Target, lli Value)
{
    if (Target <= Value) return false;
    Target = Value;
    return true;
}

void DynamicProgramming()
{
    for (int len = 2; len <= n; ++len)
        for (int i = 1; i + len - 1 <= n; ++i)
        {
            int j = i + len - 1;
            f[i][j] = infty;
            for (int k = r[i][j - 1]; k <= r[i + 1][j]; ++k)
                if (Minimize(f[i][j], f[i][k - 1] + f[k + 1][j] + freq(i, j)))
                    r[i][j] = k;
        }
    cout << f[1][n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    Enter();
    Init();
    DynamicProgramming();
}
