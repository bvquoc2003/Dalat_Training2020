#ifndef TORTUROUS_DAY
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 0x3f3f3f3f3f3f3f3f;
ll n, m;
vector<vector<ll>> A, M;
ll bt(ll mask, ll vertex)
{
    if (M[mask][vertex] != -1)
        return M[mask][vertex];
    bool full = true;
    for (ll i = m + 1; i <= 2 * m; i++)
        full &= !!(mask & (1 << i));
    if (full)
        return A[vertex][0];
    ll minval = inf;
    for (ll i = 0; i <= 2 * m; i++)
        if (!(mask & (1 << i)))
            if (i <= m || mask & (1 << (i - m)))
                minval = min(minval, A[vertex][i] + bt(mask | (1 << i), i));
    return M[mask][vertex] = minval;
}
int main()
{
#ifdef TORTUROUS_DAY
    freopen("TAXI.INP", "r", stdin);
#endif
    cin >> n;
    m = n / 2;
    A = vector<vector<ll>>(n + 1, vector<ll>(n + 1));
    for (auto &B : A)
        for (auto &x : B)
            cin >> x;
    M = vector<vector<ll>>(1 << (n + 1), vector<ll>(n + 1, -1));
    cout << bt(1, 0);
}