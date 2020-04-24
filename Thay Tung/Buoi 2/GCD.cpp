#include <bits/stdc++.h>
#define ll long long
template <typename T>
inline void Read(T& x) {
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}

template <typename T>
inline void Write(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}
using namespace std;
const int N=500005;
int n,k;
ll a[N], ST[4*N];

void update(int id, int l, int r, int i, ll v) {
    if (i<l || r<i) return ;
    if (l==r) {
        ST[id]=v;
        return;
    }
    int mid=(l+r)>>1, id1=(id<<1), id2=id1+1;
    update(id1, l, mid, i, v);
    update(id2, mid+1, r, i, v);
    ST[id] = __gcd(ST[id1], ST[id2]);
}
ll get(int id, int l, int r, int u, int v) {
    if (v<l || r<u) return 0;
    if (u<=l && r<=v) return ST[id];
    int mid=(l+r)>>1, id1=(id<<1), id2=id1+1;
    return __gcd(get(id1, l, mid, u, v), get(id2, mid+1, r, u, v));
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    freopen("GCD.INP","r",stdin);
    freopen("GCD.OUT","w",stdout);
    Read(n); Read(k);
    for (int i=1;i<=n;i++) {
        Read(a[i]);
        update(1,1,n,i,a[i]);
    }
    ll res=1;
    for (int i=1;i<=n-k+1;i++) res=max(res,get(1,1,n,i,i+k-1));
    Write(res);
    return 0;
}