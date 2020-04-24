#include <bits/stdc++.h>

using namespace std;
#define int long long

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
const int32_t N=100001;
int n, a[N], b[N];
int inc[N];
int mn_pos[N];
int mark[N];
int c[N];

int p[4];

vector<int> res;

void Try(int cur_mask,int mn) {
	//cerr << '!' << cur_mask << ' ' << mn << '\n';
	if (cur_mask == 7)
	{
		if (mn != n + 1) return;
		//for (int i=1;i<=n;i++)
		//	cerr << a[i] << ' ';
		//cerr << '\n';	
		if (b[1] != a[1] + a[2] + a[n]) return;
		if (b[n] != a[n-1] + a[n] + a[1]) return;
		bool ok = true;
		for (int i=2;i<=n-1;i++)
			if (b[i] != (a[i-1] + a[i] + a[i+1])) {
				ok = false;
				break;
			}
		if (!ok) return;
		vector<int> tmp;	
		for (int i=1;i<=n;i++) tmp.push_back(a[i]);
		if (res.empty()) {
			res = tmp;
			return;
		}
		bool opt = false;
		for (int i=0;i<res.size();i++) {
			if (res[i] < tmp[i]) {
				opt = false;
				break;
			}
			else if (res[i] > tmp[i]) {
				opt = true;
				break;
			}	
		}
		if (opt) res = tmp;
		return;					
	}
	for (int i=0;i<=2;i++)
	if (!((1<<i) & cur_mask)) {
		a[mn_pos[i+1]] = mn;
		int tmp = mn_pos[i+1];
		while(1) {
			mark[a[tmp]]++;
			int nxt = tmp + 3;
			if (nxt > n) nxt -= n;
			if (a[nxt]) break;
			a[nxt] = a[tmp] + inc[tmp];
			tmp = nxt;
		}
		int cur_mn = mn;
		while(cur_mn <= n && mark[cur_mn]) cur_mn++;	
		Try(cur_mask | (1<<i),cur_mn);
		tmp = mn_pos[i+1];
		while(1) {
			if (!a[tmp]) break;
			mark[a[tmp]]--;							
			a[tmp] = 0;
			tmp += 3;
			if (tmp > n) tmp -= n;
		}
	}
	return;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	freopen("CIRCLE.INP","r",stdin);
	freopen("CIRCLE.OUT","w",stdout);
	Read(n);
	for (int i=1;i<=n;i++) Read(b[i]);
	if (n == 1) {
		Write(1);
		return 0;
	}	
	if (n == 2) {
		Write(1);
		putchar(' ');
		Write(2);
		return 0;
	}	
	int sum = n*(n+1)/2;
	if (n%3 == 1) {
		a[1] = sum;
		for (int i=3;i<=n;i += 3) a[1] -= b[i];
		a[2] = sum;
		for (int i=4;i<=n;i += 3) a[2] -= b[i];
		for (int i=3;i<=n;i++) a[i] = (b[i-1] - a[i-2] - a[i-1]);
		for (int i=1;i<=n;i++) {
			Write(a[i]);
			putchar(' ');
		}
	}
	else if (n%3 == 2) {
		a[1] = -sum;	
		for (int i=2;i<=n;i += 3) a[1] += b[i];
		a[2] = -sum + b[1];
		for (int i=3;i<=n;i += 3) a[2] += b[i];
		for (int i=3;i<=n;i++) a[i] = (b[i-1] - a[i-2] - a[i-1]);
		for (int i=1;i<=n;i++) {
			Write(a[i]);
			putchar(' ');
		}
	}
	else {
		for (int i=2;i<=n;i++) {
			int nxt = (i+1);
			if (nxt > n) nxt = 1;
			if (i%n == 2) inc[i-1] = b[nxt] - b[i];
			else if (i%n == 0) inc[i-1] = b[nxt] - b[i];
			else inc[i-1] = b[nxt] - b[i];
		}	
		inc[n] = b[2] - b[1];
		for (int i=1;i<=3;i++) {
			mn_pos[i] = i;
			int val = 0;
			for (int j=i+3;j<=n;j+=3) {
				c[j] = c[j-3] + inc[j-3];	
				if (c[j] < val) {
					val = c[j];
					mn_pos[i] = j;
				}						
			}
		}
		for (int i=1;i<=3;i++) Try(0,i);
		for (int i=0;i<res.size();i++) {
			Write(res[i]);
			putchar(' ');
		}
	}
}