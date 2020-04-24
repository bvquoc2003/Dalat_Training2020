#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef pair <int,int> ii;
int n, m, tmax=0;
vector <int> w, res, visited;
vector <bool> mark;
vector <vector <int> > a;
void Enter() {
    freopen("DOG.INP","r",stdin);
    cin>>n;
    w.resize(n+1); a.resize(n+1);
    for (int i=1;i<=n;i++) cin>>w[i];
    cin>>m;
    for (int i=1;i<=m;i++) {
        int u, v; cin>>u>>v;
        a[u].push_back(v);
    }
    cin>>tmax;
    mark.resize(n+1);
    res.resize(n+1);
}
priority_queue < ii, vector<ii>, greater<ii> > q;
void Grrr() {
	q.push(ii(0,1));
	mark[1]=true;
	while(!q.empty()) {
        visited.clear();
		int t=q.top().first;
		if (t>tmax) break;
		while(!q.empty() && q.top().first==t) {
			int u=q.top().second; q.pop();
			res[u]++;
			visited.push_back(u);
			for (int i=0;i<a[u].size();i++) {
				int v=a[u][i];
				if (!mark[v]) {
					mark[v]=true;
					q.push(ii(t+w[v],v));
				}
			}
		}
		for (int i=0;i<visited.size();i++) mark[visited[i]]=false;
	}
    freopen("DOG.OUT","w",stdout);
    for (int i=1;i<=n;i++) cout<<res[i]<<endl;
}
int32_t main(void) {
    FastIO;
    Enter();
    Grrr();
    return 0;
}