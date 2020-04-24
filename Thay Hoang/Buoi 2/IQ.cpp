#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define val first
#define id second
using namespace std;
typedef pair <int,int> ii;
const int N=100005;
int n, res[N];
ii l[N], d[N];
int32_t main(void) {
	FastIO;
	freopen("IQ.INP","r",stdin);
	freopen("IQ.OUT","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>l[i].val;
		l[i].id=i;
	}
	for (int i=1;i<=n;i++) {
		cin>>d[i].val;
		d[i].id=i;
	}
	sort(l+1,l+1+n);
	sort(d+1,d+1+n);
	int j=1, m=0;
	for (int i=1;i<=n;i++) {
		while (j<=n && d[i]>l[j]) j++;
		if (j>n) break;
		m++; j++;
	}
    j=1;
    for (int i=n-m+1;i<=n;i++) {
    	res[l[i].id]=d[j].id;
    	j++;
    }
    for (int i=1;i<=n-m;i++) {
    	res[l[i].id]=d[j].id;
    	j++;
    }
	for (int i=1;i<=n;i++) cout<<res[i]<<' ';	
	return 0;
}
