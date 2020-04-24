#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Distance(ll a, ll b) {
    ll t=a-b;
    return abs(t);
}

ll Center(ll a, ll b) { return b-(Distance(a,b)/2); }

int n; ll L, R;
vector <ll> a;

int main()  {
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("MAXDIS.INP","r",stdin);
    freopen("MAXDIS.OUT","w",stdout);
    cin>>n>>L>>R; a.resize(n+1);
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a.begin()+1,a.end());
    ll res, mx=0;
    if (R<a[1] && mx<=Distance(a[1],L)) { mx=Distance(a[1],L); res=L; }
    if (L>a[n] && mx<=Distance(R,a[n])) { mx=Distance(R,a[n]); res=R; }

    int l=n+1, r=0;
    for (int i=1;i<=n;i++) if (L<=a[i]) { l=i; break; }
    for (int i=n;i>=1;i--) if (R>=a[i]) { r=i; break; }

    if (mx<=Distance(a[l],L)) { mx=Distance(a[l],L); res=L; }
    if (mx<=Distance(R,a[r])) { mx=Distance(R,a[r]); res=R; }

    for (int i=l; i<r; i++) {
        ll k=Center(a[i], a[i+1]);
        if (mx<=Distance(a[i+1],k)) {
            mx=Distance(a[i+1],k);
            res=k;
        }
    }
    cout << res;
    return 0;
}