#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N=100005;
#define int long long
const int mod=998244353;
int fact[N];
int re_fact[N];
int p(int a, int b) {
    if (b == 0) return 1;
    int tmp=p(a,b/2);
    if (b%2==0) return (tmp*tmp)%mod;
    return ((tmp*tmp)%mod*a)%mod;
}
int inv(int x) { return p(x, mod-2); }
int comb(int n, int k) {
    if (k>n) return 0;
    return ((fact[n]*re_fact[k])%mod*re_fact[n-k])%mod;
}
int n, cnt_x_pos=0, cnt_y_pos=0, cnt_x_neg=0, cnt_y_neg=0;
int32_t main() {
    FastIO;
    freopen("POINTS.INP","r",stdin);
    freopen("POINTS.OUT","w",stdout);
    fact[0]=1;
    for (int i=1;i<=100000;i++) fact[i]=(fact[i-1]*i)%mod;
    re_fact[100000]=inv(fact[100000]);
    for (int i=100000;i>=1;i--) re_fact[i-1]=(re_fact[i]*i)%mod;
    cin>>n;
    for (int i=1;i<=n;i++) {
        int x; cin>>x;
        if (x>0) cnt_x_pos++;
        else cnt_x_neg++;
    }
    for (int i=1;i<=n;i++) {
        int y; cin>>y;
        if (y>0) cnt_y_pos++;
        else cnt_y_neg++;
    }
    int res=0;
    for (int i=0;i<=cnt_x_pos;i++) {
        int cur=1;
        cur=(cur*comb(cnt_x_pos, i))%mod;
        cur=(cur*comb(cnt_y_pos,i))%mod;
        if (cnt_y_pos-i<0) continue;
        if (cnt_x_pos-i<0) continue;
        cur=(cur*comb(cnt_x_neg,cnt_y_pos-i))%mod;
        cur=(cur*comb(cnt_y_neg,cnt_x_pos-i))%mod;
        res=(res+cur)%mod;
    }
    cout<<res;
    return 0;
}