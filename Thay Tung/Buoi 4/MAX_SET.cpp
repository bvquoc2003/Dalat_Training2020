#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;

template <typename T>
inline void Read(T& x) {
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}
template <typename T>
inline void Write(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}

const int N=1003, oo=1e7, CanOO=sqrt(1e7);
#define int long long
int n, a[N];
struct data {
	int val, cnt;
	data() {val=0; cnt=0;}
	data(int _val, int _cnt) {val=_val; cnt=_cnt;}
	bool operator < (const data &other) {return cnt<other.cnt;}
}; vector <data> ans;
int ngto[99999999];
vector <int> primes;
void Eratosthenes() {
	for (int i=2;i<=oo;i++) ngto[i]=true;
	for (int i=2;i<=CanOO;i++)
	if (ngto[i]) for (int j=i*i;j<=oo;j+=i) ngto[j]=false;
	int spt=5e6/n;
	for (int i=2;i<=oo;i++)
		if (ngto[i]) {
			primes.push_back(i);
			if (spt==primes.size()) break;
		}
	// cerr<<primes.size();
}
int32_t main(void) {
	FastIO;
	freopen("MAX_SET.INP","r",stdin);
	freopen("MAX_SET.OUT","w",stdout);
	Read(n);
	for (int i=1;i<=n;i++) Read(a[i]);
	Eratosthenes();
	for (int x:primes) {
		int cnt=0;
		for (int i=1;i<=n;i++) if (a[i]%x==0) cnt++;
		ans.push_back(data(x,cnt));
	}
	cout<<(*max_element(ans.begin(),ans.end())).cnt;
	return 0;
}