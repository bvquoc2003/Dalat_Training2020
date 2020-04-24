#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=100005;
int n; ll l,r,a[N];
ull Distance (ll x, ll y) { return ull(y-x); }
ll Center(ll x, ll y) { return y-(ll)(Distance(x,y)/2); }
int32_t main(void) {
    FastIO;
    freopen("MAXDIS.INP","r",stdin);
    freopen("MAXDIS.OUT","w",stdout);
    cin>>n>>l>>r;
    ll st=LLONG_MIN, ss=LLONG_MIN, sn=LLONG_MIN;
    ll rest=l, ress=l, resn=l;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<n;i++) {
        if (l>a[i] && l<a[i+1] && min(abs(l-a[i]),abs(l-a[i+1]))>=st) {
            rest=l;
            st=min(abs(l-a[i]),abs(l-a[i+1]));
        }
        
        if (r<a[i+1] && r>a[i] && min(abs(r-a[i]),abs(r-a[i+1]))>=st) {
            rest=r;
            st=min(abs(r-a[i]),abs(r-a[i+1]));
        }

        ll mid=Center(a[i],a[i+1]);
        if (mid>r || mid<l) continue;
        if (mid!=a[i]) {
            ll h=abs(mid-a[i]);
            ll k=abs(mid-a[i+1]);
            if (st<=min(k,h)) {
                rest=mid;
                st=min(k,h);                
            }
            mid++;
            if (mid>=l && mid<=r && mid!=a[i+1]) {
                h=abs(mid-a[i]);
                k=abs(mid-a[i+1]);
                if (st<=min(k,h)) {
                    rest=mid;
                    st=min(k,h);                
                }
            }
        }
    }

    ll sc=LLONG_MIN,resc;
    if (l<a[1])  {
        ress=l; 
        ss=abs(a[1]-l);
    }
    if (r>a[n]) { 
        resn=r; 
        sn=abs(r-a[n]);
    }
    if (sn>=ss) {
        sc=sn;
        resc=resn;
    } else {
        sc=ss;
        resc=ress;
    }

    ll res=resc;
    if (st==sc) res=((st==LLONG_MIN)?a[n]:max(resc,rest));
    if (st>sc) res=rest;
    cout<<res;
    return 0;
}