#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define int long long
const int N=200005;
int n, m, a[N];
int psum[N], res=LLONG_MAX;
int dist(int l, int r) {
    int mid=(l+r)>>1;
    int ans=(psum[r]-psum[mid])-a[mid]*(r-mid)+a[mid]*(mid-l)-(psum[mid-1]-psum[l-1]);
    return ans;
}
int32_t main(void) {
    FastIO;
    freopen("UNLOCK.INP","r",stdin);
    freopen("UNLOCK.OUT","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++) a[n+i]=a[i]+m;
    psum[0]=0;
    for (int i=1;i<=2*n;i++) psum[i]=psum[i-1]+a[i];
    for (int i=1;i<=n;i++) res=min(res,dist(i,i+n-1));
    cout<<res;
    return 0;
}