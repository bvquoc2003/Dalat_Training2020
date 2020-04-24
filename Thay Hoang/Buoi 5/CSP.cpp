#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N=801;
#define int long long
int n, k, a[N];
int b[2*N], c[2*N], f[250][N][N];

int cost(int l,int r) {
    if (l>r) return 0;
    return r*(b[r]-b[l-1])-(c[r]-c[l-1]);
}
int dp(int p,int l,int r) {
    if (p==1) return cost(l,r);
    if (f[p][l][r]!=-1) return f[p][l][r];
    int cur=1e18;
    for (int i=l;i<=r;i++) cur=min(cur,dp(p-1,l,i)+cost(i+1,r));
    return f[p][l][r]=cur;  
}
int32_t main(void) {
    FastIO;
    freopen("CSP.INP","r",stdin);
    freopen("CSP.OUT","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        a[i+n]=a[i];
    }
    b[0]=0; c[0]=0;
    for (int i=1;i<=(n<<1);i++) {
        b[i]=b[i-1]+a[i];
        c[i]=c[i-1]+a[i]*i;
    }
    for (int i=0;i<=k+1;i++) for (int j=0;j<=2*n;j++) for (int k=0;k<=2*n;k++) f[i][j][k]=-1;
    int res=1e18;
    for (int i=1;i<=n;i++) {
        // cout<<f(k,i,i+n-1)<<" ";
        res=min(res,dp(k,i,i+n-1));
    }
    cout<<res;
    return 0;
}