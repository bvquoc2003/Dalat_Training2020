#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;

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

const int N=100005;
int n, k, a[N];
int b[N], res=INT_MAX;
deque <int> d;
int32_t main() {
    FastIO;
    freopen("MAXDIF.INP","r",stdin);
    freopen("MAXDIF.OUT","w",stdout);
    Read(n); Read(k);
    for (int i=1;i<=n;i++) Read(a[i]);
    sort(a+1,a+1+n);
    for (int i=1;i<n;i++) b[i]=a[i+1]-a[i];
    int m=n-k-1;
    for (int i=1;i<n;i++) {
        while (!d.empty() && b[i]>b[d.back()]) d.pop_back();
        d.push_back(i);
        while (!d.empty() && i>m && i-d.front()+1>m) d.pop_front();
        if (!d.empty() && i>=m) res=min(res,b[d.front()]);
    }
    Write(res);
    return 0;
}