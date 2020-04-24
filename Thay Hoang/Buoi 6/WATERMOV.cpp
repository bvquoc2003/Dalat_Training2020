#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef long long ll;
const int N=1e6+1;
struct TPoint { ll x, y; };
typedef TPoint TVector;
int n, m;
TPoint p[N], q[N];


ll operator *(const TVector& u, const TVector& v) { return u.x * v.y - u.y * v.x; }
TVector operator-(const TPoint& a, const TPoint& b) { return {b.x - a.x, b.y - a.y}; }
bool CCW(const TPoint& a, const TPoint& b, const TPoint& c) { return (b - a) * (c - b) > 0; }
ll Area(const TPoint& a, const TPoint& b, const TPoint& c) { return -((b - a) * (c - b)); }

ll Solve() {
	ll res = 0;
	m = 0;
	for (int i=0;i<=n;i++) {
		while (m>=2 && !CCW(q[m-2],q[m-1],p[i])) {
			res+=Area(q[m-2],q[m-1],p[i]);
			--m;
		}
		q[m++]=p[i];
	}
	return res;
}
int32_t main(void) {
    FastIO;
    freopen("WATERMOV.INP","r",stdin);
    freopen("WATERMOV.OUT","w",stdout);
	cin>>n;
	p[0]={0,0};
	for (int i=1;i<=n;i++) {
		p[i].x=i;
		cin>>p[i].y;
		p[i].y+=p[i-1].y;
	}
	ll res=Solve();
	cout<<(res/2)<<'.'<<((res%2==0)?'0':'5');
	return 0;
}
