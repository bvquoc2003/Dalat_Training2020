#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;
typedef long long ll;
const int N=100005;
struct Point {
    ll x, y;
    inline Point operator -(const Point& other) const { return {x-other.x, y-other.y}; }
    inline ll operator *(const Point& other) const { return x*other.y-y*other.x; }
};

int n, m;
Point p[N], q[N], A;

inline ll SqrLen(const Point& u) { return u.x*u.x+u.y*u.y; }
inline bool CCW(const Point& A, const Point& B, const Point& C) { return (B-A)*(C-B)>0LL; }

void FindA() {
    Point* ptr=min_element(p,p+n,[](const Point& p, const Point& q) {return p.y<q.y || (p.y==q.y && p.x<q.x);});
    A=*ptr;
    swap(*ptr,p[0]);
}

void Graham() {
    sort(p + 1, p + n, [](const Point& B, const Point& C) {
        Point u=B-A, v=C-A;
        ll temp=u*v;
        return temp>0 || temp==0 && SqrLen(u)<SqrLen(v);
    });
}

void FindConvexHull() {
    m=0;
    for (int i=0;i<n;i++) {
        while (m>=2 && !CCW(q[m-2],q[m-1],p[i])) --m;
        q[m++]=p[i];
    }
}

int32_t main(void) {
    FastIO;
    freopen("CONVEXHULL.INP", "r", stdin);
    freopen("CONVEXHULL.OUT", "w", stdout);
    cin>>n;
    for (int i = 0; i < n; ++i) cin>>p[i].x>>p[i].y;
    FindA();
    Graham();
    FindConvexHull();
    q[m]=q[0];
    ll res=0;
    for (int i=0;i<m;i++) res+=q[i]*q[i+1];
    cout<<m<<endl;
    cout<<res/2<<'.'<<((res%2==0)?0:5)<<endl;
    for (int i=0;i<m;i++) cout<<q[i].x<<' '<<q[i].y<<endl;
}
