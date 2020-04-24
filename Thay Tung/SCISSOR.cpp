#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
uint64_t m,n,res;
int32_t main(void) {
	FastIO;
	freopen("SCISSOR.INP","r",stdin);
	freopen("SCISSOR.OUT","w",stdout);
	cin>>m>>n;
	if (m==n) m--, n--;
	res=m*n/2LL;
	cout<<res;
	return 0;
}