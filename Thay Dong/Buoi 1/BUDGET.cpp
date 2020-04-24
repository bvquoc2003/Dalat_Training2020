#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MaxN=2003;
int64_t n, m, p, t=0;
int64_t visited[MaxN];
vector <int64_t> s, r, mark;
vector <vector<int64_t> > h;
bool visit(int64_t u) {
    if (visited[u]!=t) visited[u]=t;
    else return false;
    for (int i=0;i<h[u].size();i++) {
        if (!mark[h[u][i]] || visit(mark[h[u][i]])) {
            mark[h[u][i]]=u;
            return true;
        }
    }
    return false;
}
bool check(int64_t d) {
    for (int i=1;i<=n;i++) h[i].clear();
    for (int i=1;i<mark.size();i++) mark[i]=0;
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++)
        for (int64_t k=1;k<=n;k++)
        if ((r[i]+(p/s[j]+(p%s[j]!=0))*k)<=d+1) h[i].push_back(n*(j-1)+k);
    int cur=0;
    for (int i=1;i<=n;i++) {
        t++;
        cur+=visit(i);
    }
    return cur>=n;
}
int32_t main(void) {
    FastIO;
    freopen("BUDGET.INP","r",stdin);
    freopen("BUDGET.OUT","w",stdout);
    cin>>m>>n>>p; h.resize(n+1);
    s.resize(m+1); r.resize(n+1);
    mark.resize(m*n+n+1);
    for (int i=1;i<=m;i++) cin>>s[i];
    for (int i=1;i<=n;i++) cin>>r[i];
    int64_t l=0, r=1e18, res=1e18+1;
    while (l<=r) {
        int64_t m=(l+r)/2;
        if (check(m)) {
            res=min(m,res);
            r=m-1;
        } else l=m+1;
    }
    cout<<res;
    return 0;
}