#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N=400005;
struct query{
	int c, d, l, r;
	query() { c=0; d=0; l=0; r=0; }
	query(int _c, int _d, int _l, int _r) { c=_c; d=_d; l=_l, r=_r; }
} q[N];
int n, m, a[N];
set <int> d[N];
void Solve(query q) {
	for (int c=q.c;c<=q.d;c++) {
		if (d[c].empty()) {
			cout<<c<<"\n";
			return;
		}
		auto it=d[c].lower_bound(q.l);
		if (*it>=q.l && *it<=q.r) continue;
		cout<<c<<"\n";
		return;
	}
	cout<<"OK\n";
}
int32_t main(void) {
    FastIO;
    freopen("COLORS.INP","r",stdin);
    freopen("COLORS.OUT","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	d[a[i]].insert(i);
    }
    for (int i=1;i<=m;i++) {
    	cin>>q[i].c>>q[i].d>>q[i].l>>q[i].r;
    	Solve(q[i]);
    }
    return 0;
}