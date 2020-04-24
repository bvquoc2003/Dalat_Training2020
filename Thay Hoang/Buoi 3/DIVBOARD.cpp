#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef pair <int64_t,int64_t> ii; //first=Min | second=Max
const int N=2003;
int m, n, a[N][N];
int64_t psum[N][N];
int64_t f(int x1, int y1, int x2, int y2) { return (psum[x2][y2]-psum[x1-1][y2]-psum[x2][y1-1]+psum[x1-1][y1-1]); }
ii CutTop(int x) {
    ii re;
    int y0=0;
    int64_t delta=LLONG_MAX;
    for (int y=1;y<n;y++)
    if (abs(f(1,1,x,y)-f(1,y+1,x,n))<delta) {
        y0=y;
        delta=abs(f(1,1,x,y)-f(1,y+1,x,n));
    }
    re.first=min(f(1,1,x,y0),f(1,y0+1,x,n));
    re.second=max(f(1,1,x,y0),f(1,y0+1,x,n));
    return re;
}
ii CutBottom(int x) {
    ii re;
    int y0=0;
    int64_t delta=LLONG_MAX;
    for (int y=1;y<n;y++)
    if (abs(f(x,1,m,y)-f(x,y+1,m,n))<delta) {
        y0=y;
        delta=abs(f(x,1,m,y)-f(x,y+1,m,n));
    }
    re.first=min(f(x,1,m,y0),f(x,y0+1,m,n));
    re.second=max(f(x,1,m,y0),f(x,y0+1,m,n));
    return re;
}
int64_t res=LLONG_MAX;
int32_t main(void) {
    FastIO;
    freopen("DIVBOARD.INP","r",stdin);
    freopen("DIVBOARD.OUT","w",stdout);
    cin>>m>>n;
    for (int i=1;i<=m;i++) for (int j=1;j<=n;j++) {
        cin>>a[i][j];
        psum[i][j]=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]+a[i][j];
    }
    for (int x=1;x<m;x++) {
        ii Top=CutTop(x), Bot=CutBottom(x+1);
        int64_t Max=max(Top.second,Bot.second), Min=min(Top.first,Bot.first);
        res=min(res,(Max-Min));
    }
    cout<<res;
    return 0;
}