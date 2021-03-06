#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;

template <typename T>
inline void Read(T& x) {
    bool Neg=false;
    char c;
    for (c=getchar(); c < '0' || c > '9'; c=getchar())
        if (c == '-') Neg=!Neg;
    x=c-'0';
    for (c=getchar(); c >= '0' && c <= '9'; c=getchar())
        x=x * 10+c-'0';
    if (Neg) x=-x;
}
template <typename T>
inline void Write(T x) {
    if (x < 0) { putchar('-'); x=-x; }
    T p=1;
    for (T temp=x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p+'0');
}

int32_t main() {
	FastIO;
	freopen("TRINES.INP","r",stdin);
	freopen("TRINES.OUT","w",stdout);
	int64_t a[4];
	Read(a[1]); Read(a[2]); Read(a[3]);
	sort(a+1,a+1+3);
	int64_t res=(a[2]-a[1])+(a[3]+(a[2]-a[1])-a[2]);
	Write(res);
	return 0;
}