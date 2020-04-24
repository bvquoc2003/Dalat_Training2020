#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define int long long
int n,m;
int32_t main() {
	FastIO;
	freopen("SCISSOR.INP","r",stdin);
	freopen("SCISSOR.OUT","w",stdout);
	cin>>n>>m;
	int x, y;
	int cnt_x=m-1, tmp=n-1;
	x=tmp*(tmp+1)>>1;
	if (tmp>cnt_x) {
		int z=(tmp-cnt_x);
		x-=z*(z+1)>>1;
	}
	int cnt_y=n-1; tmp=m-2;
	y=tmp*(tmp+1)>>1;
	if (tmp>cnt_y) {
		int z=(tmp-cnt_y);
		y-=z*(z+1)>>1;
	}
	int res=x+y;
	cout<<res;
	return 0;
}