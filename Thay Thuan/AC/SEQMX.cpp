#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const double epsilon=1e-8;
int n, k;
vector <double> a, s(1), f;
bool check(double mid) {
    double res=INT_MIN;
    vector <double> b(1);
    for (int i=1;i<=n;i++) b.push_back(a[i]-mid);
    for (int i=1;i<=n;i++) {
        s[i]=s[i-1]+b[i];
        f[i]=max(f[i-1]+b[i],b[i]);
    }
    for (int i=k;i<=n;i++) {
        res=max(res,max(0.0,f[i-k])+s[i]-s[i-k]);
        if(res>=0) return true;
    }
    return false;
}
double ans;
int32_t main(void) {
    FastIO;
    freopen("SEQMX.INP","r",stdin);
    freopen("SEQMX.OUT","w",stdout);
    cin>>n>>k; a.resize(n+1);
    for (int i=1;i<=n;i++) cin>>a[i];
    if (n<=5000) {
        for (int i=1;i<=n;i++) s.push_back(s[i-1]+a[i]);
        for (int i=1;i+k-1<=n;i++) for (int j=i+k-1;j<=n;j++) ans=max(ans,(s[j]-s[i-1])/double(j-i+1));
        cout<<fixed<<setprecision(5)<<ans;
        return 0;
    }
    f.resize(n+1); s.resize(n+1);
    double l=-1e5, r=1e5;
    while (r-l>=epsilon) {
        double mid=double(l+r)/2;
        if(check(mid)) {
            ans=mid;
            l=mid+epsilon;
        } else r=mid-epsilon;
    }
    cout<<fixed<<setprecision(5)<<ans;
    return 0;
}