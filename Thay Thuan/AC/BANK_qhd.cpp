#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
struct data {
    int d, t;
    data () {d=0; t=0;}
    data (int _d, int _t) {d=_d; t=_t;}
    bool operator <(const data &x) {return t<x.t || (t==x.t && d>x.d);}
};
int n, T; vector <data> a;
vector <vector<int> > f;
int32_t main(void) {
    FastIO;
    // freopen("BANK.INP","r",stdin);
    // freopen("BANK.OUT","w",stdout);
    cin>>n>>T; a.resize(n+1);
    for (int i=1;i<=n;i++) cin>>a[i].d>>a[i].t;
    sort(a.begin()+1,a.end());
    f.resize(n+1,vector<int>(T+1,0));
    for (int i=1;i<=n;i++) for (int j=0;j<=a[i].t;j++) {
        if (j==0) {
            f[i][j]=max(f[i-1][j],a[i].d);
            continue;
        }
        f[i][j]=max(f[i-1][j],f[i-1][j-1]+a[i].d);
    }
    cout<<*max_element(f[n].begin()+1,f[n].end());
    return 0;
}

