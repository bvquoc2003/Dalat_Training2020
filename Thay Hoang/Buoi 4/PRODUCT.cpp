#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N=1e5+5, MOD=123456789;
#define int long long
int n, k, a[N], t;

int32_t main(void) {
	FastIO;
	freopen("PRODUCT.INP","r",stdin);
	freopen("PRODUCT.OUT","w",stdout);
	int ntests; cin>>ntests;
	while (ntests--) {
		cin>>n>>k;
		for (int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n);
		int res=1;
		if (!(k&1)) {
			int l=1,r=n;
			while (k) {
				if (a[l]*a[l+1]>a[r]*a[r-1]) {
					res=((res*a[l])%MOD*a[l+1])%MOD;
					l+=2;
				}
				else {
					res=((res*a[r])%MOD*a[r-1])%MOD;
					r-=2;
				}
				k-=2;
			}
		}
		else {
			if (a[n]<=0)
				for (int i=n;i>=n-k+1;i--) 
					res=((res*a[i])%MOD+MOD)%MOD;
			else {
				res=a[n];
				int l=1, r=n-1;
				k--;
				while(k) {
					if (a[l]*a[l+1]>a[r]*a[r-1]) {
						res=((res*a[l])%MOD*a[l+1])%MOD;
						l+=2;
					}
					else {
						res=((res*a[r])%MOD*a[r-1])%MOD;
						r-=2;
					}
					k-=2;
				}			
			}
		}
		res=(res+MOD)%MOD;
		cout<<res<<'\n';
	}
	return 0;
}

/*

k chẵn
Sort tăng dần (a1,a2,a3,a4,...,an)
chọn (k/2) cặp có tích lớn nhất

k lẻ
	a[n]<0: chọn k số lớn nhất
	a[n]>=0: chọn a[n] --> quy về TH (k chẵn)

*/