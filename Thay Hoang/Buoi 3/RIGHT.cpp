#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define int long long
const int N=100005;
int n, d, a[N];
int m, b[N], f[N];
/* f[i]: độ dài dãy con tăng dài nhất kết thúc tại a[i]
    -->res[i]=f[i]*delta+a[i] */
int32_t main(void) {
    FastIO;
    freopen("RIGHT.INP","r",stdin);
    freopen("RIGHT.OUT","w",stdout);
    cin>>n>>d;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
        f[i]=lower_bound(b+1,b+m+1,a[i])-b;
        m=max(m,f[i]);
        b[f[i]]=a[i];
    }
    for (int i=1;i<=n;i++) cout<<f[i]*d+a[i]<<endl;
    return 0;
}