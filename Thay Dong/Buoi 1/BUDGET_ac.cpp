#include <bits/stdc++.h>

using namespace std;
const int maxN = 1111;
long long n,m,p,s[maxN],r[maxN];
long long Visited[maxN],t=0,ass[maxN*maxN+maxN];
vector<long long> h[maxN];
bool visit(long long u) {
    if (Visited[u]!=t)
        Visited[u]=t;
    else
        return false;

    for (auto x:h[u]){
        if (!ass[x] || visit(ass[x])) {
            ass[x]=u;
            return true;
        }
    }
    return false;
}
bool check(long long d){
    for (int i=1; i<=n; ++i) h[i].clear();
    for (int i=1; i<=m*n+n; ++i) ass[i]=0;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            for (long long k=1; k<=n; ++k)
                if ((r[i]+(p/s[j]+(p%s[j]!=0))*k)<=d+1){
                    h[i].push_back(n*(j-1)+k);
                }
    int rt=0;
    for (int i=1; i<=n; ++i)t++, rt+=visit(i);
    return rt>=n;
}
int main()
{
    ifstream cin("BUDGET.INP");ofstream cout("BUDGET.OUT");
    cin >> m >> n >> p;
    for (int i=1; i<=m; ++i) cin >> s[i];
    for (int i=1; i<=n; ++i) cin >> r[i];
    long long l=0,r=1e18,res=1e18+1;
    while (l<=r){
        long long m=(l+r)/2;
        if (check(m)) res=min(m,res),r=m-1;
        else l=m+1;
    }
    cout << res;
    return 0;
}
