#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N=200005;
int n, a[N], fen[N];
void update(int p, int val) { // a[p]+=val;
	for(int i=p;i<=n;i+=i&-i) fen[i]+=val;
	a[p]+=val;
}
int sum(int p) { //a[1]+a[2]+...+a[p]
	int ans=0;
	for(int i=p;i;i-=i&-i) ans+=fen[i];
	return ans;
}
int32_t main(void) {
	FastIO;
	freopen("BIT.INP","r",stdin);
	freopen("BIT.OUT","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) {
		int x; cin>>x;
		update(i,x);
	}
	for (int i=1;i<=n;i++) cerr<<i-(i&-i)<<" "<<i<<endl;
	int q; cin>>q;
	for (int i=1;i<=n;i++) cout<<a[i]<<" "; cout<<endl;
	while (q--) {
		bool type; cin>>type;
		if (type) {
			int p; cin>>p; //Xuat a[1]+a[2]+...+a[p];
			cout<<sum(p)<<endl;
		} else {
			int p, val;
			cin>>p>>val; // a[p]+=val
			update(p,val);
			for (int i=1;i<=n;i++) cout<<a[i]<<" "; cout<<endl;
		}
	}
	return 0;
}