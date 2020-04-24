#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 998244353;
const int MaxN = 600050;

int n, m;
vector<int> a[MaxN];

bool ok = true;
queue<int> d;
bool cx[MaxN];
int cl[MaxN], c, l;

void BFS(int _u) {
    d.push(_u);
    cx[_u]=false;
    cl[_u]=1;
    while (!d.empty()) {
        int u = d.front(); d.pop();
        if (cl[u] == 1) c++; else l++;
        for (int v:a[u]) {
            if (cl[v] != 0) {
				if (cl[v] == cl[u]) { ok = false; return ; }
				continue;
			}
            if (cx[v]) {
                cl[v]=cl[u]*-1;
                d.push(v);
                cx[v]=false;
            }
        }
    }
}

int32_t main(void) {
	freopen("BGRAPH.INP","r",stdin);
	freopen("BGRAPH.OUT","w",stdout);
    cin>>n>>m;
    int u, v;
    for (int i=1;i<=m;i++) {
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for (int i=1;i<=n;i++){
        cx[i]=true;
        cl[i]=0;
    }

    int64_t res=1;
    for (int i=1;i<=n;i++) if (cx[i]) {
        c=l=0;
        BFS(i);
        if (!ok) { cout << "0"; return 0; }
        if (c + l == 1) {res *= 3; continue; }
        int64_t powC=1; while (c--) powC=powC*2%MOD;
        int64_t powL=1; while (l--) powL=powL*2% MOD;
        res*=(powC+powL)%MOD;
    }

    cout<<res;
    return 0;
}