#define taskname "RIDER"
#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;
typedef long long lli;
const int maxM = 1e5 + 1;
const lli Mul = 1e12;
const int Prec = 12;

int m, n, z;

struct TVector
{
    lli x, y;
    lli inline operator *(const TVector& other) const
    {
        return x * other.y - y * other.x;
    }
    TVector inline operator -(const TVector& other) const
    {
        return {x - other.x, y - other.y};
    }
};
typedef TVector TPoint;

TVector p[maxM];

template <typename T>
inline void ReadInt(T& x)
{
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar());
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
}

template <typename T>
void WriteInt(T x, int w = 1)
{
    if (x == 0 && w <= 0) return;
    WriteInt(x / 10, w - 1);
    putchar(x % 10 + '0');
}

bool CW(const TPoint& a, const TPoint& b, const TPoint& c)
{
    TVector u = b - a, v = c - b;
    return u * v < 0LL;
}

void ReadInput()
{
    ReadInt(m);
    z = 0;
    for (int i = 1; i <= m; ++i)
    {
        TPoint q;
        q.x = i;
        ReadInt(q.y);
        while (z >= 2 && !CW(p[z - 1], p[z], q)) --z;
        p[++z] = q;
    }
}

void Cal(lli t)
{
    TPoint q = {0, t};
    int low = 1, high = z - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (CW(q, p[mid], p[mid + 1])) high = mid - 1;
        else low = mid + 1;
    }
    lli DeltaT = p[low].y - t;
    lli DeltaS = p[low].x;
    lli quotient = (DeltaS * Mul) / DeltaT;
    lli remainder = (DeltaS * Mul) % DeltaT;
    if (2 * remainder >= DeltaT) ++quotient;
    WriteInt(quotient / Mul);
    putchar('.');
    WriteInt(quotient % Mul, Prec);
    putchar('\n');
}

void Solve()
{
    ReadInt(n);
    while (n-- > 0)
    {
        lli t;
        ReadInt(t);
        Cal(t);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".INP", "r", stdin);
    freopen(taskname".OUT", "w", stdout);
    ReadInput();
    Solve();
}
