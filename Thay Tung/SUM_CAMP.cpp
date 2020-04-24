#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
typedef pair<int,int> ii;
const int N=100005;
int val[N], par[N], sz[N];
set<int> s[N];
vector<int> ke[N];
int n, m, k;
int q;
int Root(int x) {
    if (par[x]==x) return x;
    return par[x]=Root(par[x]);
}
void Join(int x,int y) {
    int ax=Root(x), ay=Root(y);
    if (sz[ax]<sz[ay]) swap(ax,ay);
    sz[ax]+=sz[ay];
    par[ay]=ax;
    for (set<int>::iterator it2=s[ay].begin();it2!=s[ay].end();it2++) {
        int v=*it2;
        for (int i=0;i<ke[v].size();i++) {
            int u=ke[v][i];
            set<int>::iterator it1=s[ax].find(u);
            if (it1!=s[ax].end()) {
                u=*it1;
                val[u]++;
                val[v]++;
            }
        }
    }
    for (set<int>::iterator it=s[ay].begin();it!=s[ay].end();it++) s[ax].insert(*it);
}
int32_t main() {
    FastIO;
    freopen("SUM_CAMP.INP","r",stdin);
    freopen("SUM_CAMP.OUT","w",stdout);
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++) {
        s[i].insert(i);
        par[i]=i;
        sz[i]=1;
    }
    for (int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    for (int i=1;i<=k;i++) {
        int u,v;
        cin>>u>>v;
        if (Root(u)!=Root(v))
        Join(u,v);
    }
    cin>>q;
    while(q--) {
        char type;
        cin>>type;
        if (type=='?') {
            int u;
            cin>>u;
            cout<<val[u]<<'\n';
        } else if (type=='F') {
            int u,v;
            cin>>u>>v;
            ke[u].push_back(v);
            ke[v].push_back(u);
            if (Root(u)==Root(v)) {
                val[u]++;
                val[v]++;
            }
        } else if (type=='T') {
            int u,v;
            cin>>u>>v;
            if (Root(u)!=Root(v)) Join(u,v);
        }
    }
    return 0;
}