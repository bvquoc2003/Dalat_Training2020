#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;

const int N=1003;
int n, m, s, t[N], p[N];

int32_t main(void) {
	FastIO;
	freopen("DEFICIENCY.INP","r",stdin);
	freopen("DEFICIENCY.OUT","w",stdout);
	cin>>n>>m>>s;
	// cerr<<n<<" "<<m<<" "<<s<<endl;
	for (int i=1;i<=n;i++) {
		int x, y, z;
		cin>>x>>y>>z;
		// cerr<<x<<" "<<y<<" "<<z<<endl;
		if (x>0) t[z]+=x;
		else p[y]+=x;
	}
	for (int i=1;i<=m;i++) {
		s+=p[i];
		if (s<0) {
			cout<<"YES";
			return 0;
		}
		s+=t[i];
	}
	cout<<"NO";
	return 0;
}