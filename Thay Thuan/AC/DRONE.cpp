#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, k;
vector <int> a, c;
vector <vector<int> > f;
int res=-1;
int32_t main(void) {
    FastIO;
    freopen("DRONE.INP","r",stdin);
    freopen("DRONE.OUT","w",stdout);
    cin>>n>>k;
    a.resize(n+1); c.resize(n+1);
    for (int i=1;i<=n;i++) cin>>c[i];
    for (int i=1;i<=n;i++) cin>>a[i];
    f.resize(n+1,vector<int>(k+1,0));
    f[n][0]=c[n];
    for (int i=n-1;i>=1;i--) 
    for (int j=1;j<=k;j++) 
    for (int l=i+1;l<=a[i]+i;l++) 
    if (l<=n && f[l][j-1]>0) f[i][j]=max(f[i][j],f[l][j-1]+c[i]);
    for (int i=1;i<=k;i++) res=max(res,f[1][i]);
    if (res==0) res=-1;
    cout<<res;
    return 0;
}