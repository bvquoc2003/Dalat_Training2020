#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
const int MaxN=105050;
bool ok=false;
int n, m, k, x, cnt;
vector <bool> res;
int Trace[MaxN];
void Try(int u) {
	for (int i=0; i<=1; i++) {
		if (ok) return;
		res[u]=i;
		if (i==1) Trace[u]=0;
		else Trace[u]=Trace[u-1]+1;
		if (Trace[u]==x) continue;
		if (u<n) Try(u+1);
		else {
			cnt++;
			if (cnt==k) {
				for (int j=1;j<=n;j++) cout<<res[j]<<" ";
				ok=true;
				return;
			}
		}
	}
}

int32_t main(void) {
	FastIO;
	freopen("BINARYLIST.INP","r",stdin);
	freopen("BINARYLIST.OUT","w",stdout);
	cin>>n>>k>>x;
	res.resize(n+1);
	Try(1);
	if (!ok) cout<<"-1";
	return 0;
}