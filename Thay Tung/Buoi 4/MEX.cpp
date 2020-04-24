#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N=100005;
int n, k, a[N];
int32_t main(void) {
    FastIO;
    freopen("MEX.INP","r",stdin);
    freopen("MEX.OUT","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n); a[0]=0;
	// for (int i=1;i<=n;i++) cerr<<a[i]<<" "; cerr<<endl;
	// cerr<<k<<endl;
	for (int i=1;i<=n;i++) {
		if (k>(a[i]-a[i-1]-1)) {
			// cerr<<k<<" "<<a[i]-a[i-1]-1<<" ";
			k-=(a[i]-a[i-1]-1);
			// cerr<<k<<endl;
		}
		else {
			cout<<a[i-1]+k;
			return 0;
		}
	}
	cout<<a[n]+k;
	return 0;
}