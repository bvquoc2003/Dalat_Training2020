#define taskname "CONVEXHULL"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
using lli = long long;
const int maxN = 1e5;
struct TVector
{
    lli x, y;
    inline TVector operator -(const TVector& other) const
    {
        return {x - other.x, y - other.y};
    }
    inline lli operator *(const TVector& other) const
    {
        return x * other.y - y * other.x;
    }
};
using TPoint = TVector;
int n, m;
TPoint p[maxN], q[maxN + 1], A;

inline lli SqrLen(const TVector& u)
{
    return u.x * u.x + u.y * u.y;
}

inline bool CCW(const TPoint& A, const TPoint& B, const TPoint& C)
{
    return (B - A) * (C - B) > 0;
}

void Enter()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> p[i].x >> p[i].y;
}

void FindA()
{
    TPoint* ptr = min_element(p, p + n, [](const TPoint& p, const TPoint& q)
    {
        return p.y < q.y || (p.y == q.y && p.x < q.x);
    });
    A = *ptr;
    swap(*ptr, p[0]);
}

void GrahamScan()
{
    sort(p + 1, p + n, [](const TPoint& B, const TPoint& C)
    {
        TVector u = B - A, v = C - A;
        lli temp = u * v;
        return temp > 0 || temp == 0 && SqrLen(u) < SqrLen(v);
    });
}

void FindConvexHull()
{
    m = 0;
    for (int i = 0; i < n; ++i)
    {
        while (m >= 2 && !CCW(q[m - 2], q[m - 1], p[i]))
            --m;
        q[m++] = p[i];
    }
}

void Print()
{
    q[m] = q[0];
    lli res = 0;
    for (int i = 0; i < m; ++i)
        res += q[i] * q[i + 1];
    cout << m << '\n';
    cout << res / 2 << '.' << (res % 2 == 0 ? 0:5) << '\n';
    for (int i = 0; i < m; ++i)
        cout << q[i].x << ' ' << q[i].y << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".INP", "r", stdin);
    freopen(taskname".OUT", "w", stdout);
    Enter();
    FindA();
    GrahamScan();
    FindConvexHull();
    Print();
}
