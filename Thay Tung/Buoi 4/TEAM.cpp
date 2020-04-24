#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;

template <typename T>
inline void Read(T& x) {
    bool Neg=false;
    char c;
    for (c=getchar(); c<'0' || c>'9'; c=getchar()) if (c=='-') Neg=!Neg;
    x=c-'0';
    for (c=getchar(); c>='0' && c<='9'; c=getchar()) x=x*10+c-'0';
    if (Neg) x=-x;
}
template <typename T>
inline void Write(T x) {
    if (x<0) { putchar('-'); x=-x; }
    T p=1;
    for (T temp=x/10;temp>0;temp/=10) p*=10;
    for (;p>0;x%=p,p/=10) putchar(x/p+'0');
}

const int N=200005;
typedef pair<int64_t,int64_t> pll;
int n,ia; int64_t a,b,t,s=0;
vector <pll> ba;
vector <int64_t> f;
int32_t main() {
    FastIO;
    freopen("TEAM.INP","r",stdin);
    freopen("TEAM.OUT","w",stdout);
    Read(n); ba.resize(n+1); f.resize(n+1);
    for(int i=1;i<=n;i++) {
        Read(a); Read(b);
        ba[i]=pll(b,a);
    }
    sort(ba.begin()+1,ba.end());
    auto mi_iter=min_element(ba.begin()+1,ba.end(),[](const pll &a, const pll &b) { return a.second<b.second; });
    a=(*mi_iter).second; ia=(mi_iter-ba.begin());
    b=0;
    for(int i=1;i<=n;i++) {
        t=ba[i].first-ba[i].second;
        if(b<t) b=t;
        if(i<ia) {
            f[i]=s+a; 
            s+=ba[i].first;
            continue;
        }
        s+=ba[i].first;
        f[i]=s-b;
    }
    for(int i=1;i<=n;i++) {
        Write(f[i]);
        putchar('\n');
    }
    return 0;
}