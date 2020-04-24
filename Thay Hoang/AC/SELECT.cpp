#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int N=200001;

#define int long long
typedef pair<int,int> ii;

int par[N];
int v[N];

int anc(int x) {
	if (par[x]==x) return x;
	return par[x]=anc(par[x]);
}

void join(int x,int y) {
	v[anc(y)]+=v[anc(x)];
	par[anc(x)]=anc(y);
}

struct Edge {
	int u,v;
	Edge(){}
}E[N];

struct Query {
	char type;
	int i,val;
	Query(){}
} Q[N];

int n,m,q;
int w[N];
int ans[N];
bool mark[N];
bool check_anc[N];

set<ii, greater<ii>> s;
int32_t main(void) {
	FastIO;
	freopen("SELECT.INP","r",stdin);
	freopen("SELECT.OUT","w",stdout);
	cin>>n>>m>>q;
	for (int i=1;i<=n;i++) {
		par[i]=i;
		cin>>w[i];
	}
	for (int i=1;i<=m;i++) cin>>E[i].u>>E[i].v;
	for (int i=1;i<=q;i++) {
		cin>>Q[i].type;
		if (Q[i].type=='D') {
			cin>>Q[i].i;
			mark[Q[i].i]=true;
		}
		else  {
			cin>>Q[i].i>>Q[i].val;
			swap(Q[i].val,w[Q[i].i]);
		}
	}
	for (int i=1;i<=n;i++) v[i]=w[i];
	for (int i=1;i<=m;i++)
		if (!mark[i])
			if (anc(E[i].u) != anc(E[i].v))
				join(E[i].u,E[i].v);
	for (int i=1;i<=n;i++)
		if (!check_anc[anc(i)]) {
			check_anc[anc(i)] = true;
			s.insert(ii(v[anc(i)],anc(i)));
		}
	ans[q] = (*s.begin()).first;
	for (int i=q;i>=2;i--) {
		if (Q[i].type == 'D') {
			//cerr << E[Q[i].i].u << ' ' << E[Q[i].i].v << '\n';
			if (anc(E[Q[i].i].u) != anc(E[Q[i].i].v)) {
				s.erase(ii(v[anc(E[Q[i].i].u)],anc(E[Q[i].i].u)));
				s.erase(ii(v[anc(E[Q[i].i].v)],anc(E[Q[i].i].v)));
				join(E[Q[i].i].u,E[Q[i].i].v);
				s.insert(ii(v[anc(E[Q[i].i].v)],anc(E[Q[i].i].v)));
			}
		}
		else {
			//cerr << Q[i].val << '\n';
			s.erase(ii(v[anc(Q[i].i)],anc(Q[i].i)));
			v[anc(Q[i].i)] -= w[Q[i].i];
			w[Q[i].i] = Q[i].val;
			v[anc(Q[i].i)] += w[Q[i].i];
			s.insert(ii(v[anc(Q[i].i)],anc(Q[i].i)));
		}
		ans[i-1] = (*s.begin()).first;
		//cerr << '?' << ' ' << ans[i-1] << '\n';
	}
	for (int i=1;i<=q;i++) cout << ans[i] << '\n';
}