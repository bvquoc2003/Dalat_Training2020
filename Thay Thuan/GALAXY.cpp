#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef pair<int,int> ii;
typedef set<int> List;
struct Edge {
    int u, v, w;
    Edge() {u=0; v=0; w=0;}
    Edge(int U, int V, int W) {u=U; v=V; w=W;}
}; bool operator < (const Edge &p, const Edge &b) {return p.w<b.w;}
int n, m;
vector <int> p;
struct Disjoint_Set {
    vector<int> cha, rank;
    Disjoint_Set(int n) {
        cha.resize(n+1);
        rank.resize(n+1,0);
        for (int i=1; i<=n; i++) cha[i] = i;
    }
    int find(int u) {
        if (cha[u] != u) cha[u] = find(cha[u]);
        return cha[u];
    }
    bool join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (rank[u] == rank[v]) rank[u]++;
        if (rank[u] > rank[v]) cha[v] = u;
        else cha[u] = v;
        return true;
    }
};
typedef pair<int,int> ii;
vector <ii> res;
vector <List> b;
vector<Edge> e;
void Enter() {
	freopen("GALAXY.INP","r",stdin);
    freopen("GALAXY.OUT","w",stdout);
    cin>>n>>m; p.resize(n+1);
    for (int i=1;i<=n;i++) cin>>p[i];
	int x, u, v; b.resize(n+1);
    while (m--) {
		cin>>x>>u>>v;
		if (v<u) swap(u,v);
		for (int j=u;j<=v;j++) {
			b[x].insert(j);
			b[j].insert(x);
		}
	}
	for (int i=1;i<=n;i++)
		for (List::iterator it=b[i].begin();it!=b[i].end();++it) {
			e.push_back(Edge(i,*it,p[i]+p[*it]));
			e.push_back(Edge(*it,i,p[i]+p[*it]));
		}
}
int32_t main(void) {
    FastIO;
    Enter();
    m=e.size(); sort(e.begin(), e.end());
    Disjoint_Set Set(n); Edge E;
    int result = 0;
    for (int i=0;i<m;i++) {
        E=e[i];
		// cout<<E.u<<" "<<E.v<<" "<<E.w<<endl;
        if (Set.join(E.u, E.v)) {
            // res.push_back(ii(E.u,E.v));
            result+=E.w;
        }
    }
	cout<<result;
    // for (int i=0;i<res.size();i++) cout<<endl<<res[i].first<<" "<<res[i].second;
    return 0;
}