#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef long long ll;
const int M=1e5+1, Prec=12;
const ll Mul=1e12;

struct TPoint {
    ll x, y;
    ll operator *(const TPoint& other) const { return x*other.y-y*other.x; }
    TPoint operator -(const TPoint& other) const { return {x - other.x, y - other.y}; }
} p[M];
bool CWW(const TPoint& a, const TPoint& b, const TPoint& c) {
    TPoint u=b-a, v=c-b;
    return u*v<0LL;
}

int m, n, z;

void Calc(ll t) {
    TPoint q={0,t};
    int L=1, R=z-1;
    while (L<=R) {
        int mid=(L+R)/2;
        if (CWW(q,p[mid],p[mid+1])) R=mid-1;
        else L=mid+1;
    }
    ll DeltaT=p[L].y-t, DeltaS=p[L].x;
    ll quotient=(DeltaS*Mul)/DeltaT, remainder=(DeltaS*Mul)%DeltaT;
    if (2*remainder>=DeltaT) ++quotient;
    long double res=(long double) quotient/(Mul*1.0);
    cout<<fixed<<setprecision(12)<<res<<endl;
}

int32_t main(void) {
    FastIO;
    freopen("RIDER.INP","r",stdin);
    freopen("RIDER.OUT","w",stdout);
    cin>>m;
    z=0;
    for (int i=1;i<=m;i++) {
        TPoint q;
        q.x=i;
        cin>>q.y;
        while (z>=2 && !CWW(p[z-1],p[z],q)) --z;
        p[++z]=q;
    }
    cin>>n;
    while (n--) {
        ll t;
        cin>>t;
        Calc(t);
    }
    return 0;
}
