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

int n, w; vector <int> a,x;
int res=0;
int s=0, len=0;
void LIS() {
    res=1;
    x[0]=INT_MIN;
    for (int i=1;i<=n;i++) x[i]=INT_MAX;
    for (int i=1;i<=n;i++) {
        int l=1, r=n;
        while (l<=r) {
            int mid=(l+r)/2;
            if (x[mid]>=a[i]) r=mid-1;
            else l=mid+1;
        }
        x[r+1]=a[i];
    }
    for (int i=n;i>0;i--)
    if (x[i]!=INT_MAX) {
        res=i;
        break;
    }
}
const int N=502;
int f[N][N];
void DP() {
    for (int i=1;i<=n;i++) 
        for (int j=1;j<=n;j++)
            f[i][j]=INT_MAX;
    for (int i=1;i<=n;i++) 
        if (a[i]<=w) 
            f[i][1]=a[i];
    for (int i=1;i<=n;i++)
        for (int l=1;l<=i;l++)
            for (int j=1;j<i;j++)
                if (f[j][l-1]<INT_MAX && a[j]<a[i]) 
                    f[i][l]=min(f[i][l],f[j][l-1]+a[i]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=i;j++)
            if (f[i][j]<=w)
                res=max(res,j);
}
int32_t main(void) {
    FastIO;
    freopen("WISEQ.INP","r",stdin);
    freopen("WISEQ.OUT","w",stdout);
    Read(n); Read(w);
    a.resize(n+1); x.resize(n+1);
    for (int i=1;i<=n;i++) Read(a[i]);
    if (n<=500) DP();
    else LIS();
    Write(res);
    return 0;
}