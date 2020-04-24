#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;

const int N=200005;

template <typename T>
inline void Read(T& x) {
    bool Neg=false;
    char c;
    for (c=getchar();c<'0' || c>'9';c=getchar()) if (c=='-') Neg=!Neg;
    x=c-'0';
    for (c=getchar();c>='0' && c<='9';c=getchar()) x=x*10+c-'0';
    if (Neg) x=-x;
}
template <typename T>
inline void Write(T x) {
    if (x<0) { putchar('-'); x=-x; }
    T p=1;
    for (T temp=x/10;temp>0;temp/=10) p*=10;
    for (;p>0;x%=p,p/=10) putchar(x/p+'0');
}

typedef pair<int,int> ii;
void compress(vector<int> &a) {
    set<int> s(a.begin(), a.end());
    vector<int> b(s.begin(), s.end());
    for (int &x:a) x=lower_bound(b.begin(),b.end(),x)-b.begin()+1;
}
int n; vector <int> a;
vector <int> del;
int res[N];
int32_t main(void) {
	FastIO;
	freopen("NEXUS.INP","r",stdin);
	freopen("NEXUS.OUT","w",stdout);
	Read(n); a.resize(n);
	for (int &x:a) Read(x);
	compress(a);
	int ma=*max_element(a.begin(),a.end());
	for (int x:a) {
		if (x!=ma) Write(x);
		else Write(0);
		putchar(' ');
	}
	return 0;
}


	// int rank=0;
	// while (!a.empty()) {
	// 	int sz=a.size(); rank++;
	// 	del.clear();
	// 	if (a.size()<3) break;
	// 	// if (a.size()==1) {
	// 	// 	res[a[0].second]=rank;
	// 	// 	a.erase(a.begin());
	// 	// 	continue;
	// 	// }
	// 	// if (a.size()==2) {
	// 	// 	if (a[0]>a[1]) {
	// 	// 		res[a[1].second]=rank;
	// 	// 		a.erase(a.begin()+1);
	// 	// 	} else if (a[0]<a[1]) {
	// 	// 		res[a[0].second]=rank;
	// 	// 		a.erase(a.begin());
	// 	// 	} else {
	// 	// 		res[a[0].second]=rank;
	// 	// 		res[a[1].second]=rank;
	// 	// 		a.erase(a.begin());
	// 	// 		a.erase(a.begin());
	// 	// 	}
	// 	// 	continue;
	// 	// }
	// 	int i=0;
	// 	while (i<n) {
	// 		if (a[i]<a[(i+1)%n] && a[i]<a[(i+n-1)%n]) {
	// 			del.push_back(i);
	// 			i+=2;
	// 		} else i++;
	// 	}
	// 	for (int x:del) {
	// 		res[a[x].second]=rank;
	// 		a.erase(a.begin()+x);
	// 	}
	// }
	// for (int i=1;i<=n;i++) cout<<res[i]<<" ";