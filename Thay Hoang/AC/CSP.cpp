/*
#dynamic programming, #matrix multiplication, #knuth optimization
*/
#define taskname "CSP"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxN = 800;
const int maxCost = maxN * 1000000;
const int maxN2 = 2 * maxN;
using TMatrix = int[maxN2 + 1][maxN2 + 1];

int n, k, n2;
int cnt[maxN2 + 1], acc[maxN2 + 1];
TMatrix MatA, MatB, MatC, trace;

inline int ReadInt()
{
    char c;
    while (c = getchar(), c < '0' || c > '9');
    int x = c - '0';
    while (c = getchar(), c >= '0' && c <= '9')
        x = x * 10 + c - '0';
    return x;
}

void WriteInt(int x)
{
    if (x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}

inline bool Minimize(int& Target, int Value)
{
    if (Value < Target)
    {
        Target = Value;
        return true;
    }
    return false;
}

void ReadInput()
{
    n = ReadInt();
    k = ReadInt();
    cnt[0] = 0;
    for (int i = 1; i <= n; ++i)
        cnt[i] = ReadInt();
    n2 = n * 2;
    copy(cnt + 1, cnt + n + 1, cnt + n + 1);
    acc[0] = 0;
    for (int i = 1; i <= n2; ++i)
        acc[i] = acc[i - 1] + cnt[i] * i;
    for (int i = 1; i <= n2; ++i)
        cnt[i] += cnt[i - 1];
}

//Chi phí chuyển mọi hs in [low, high] về vị trí high
inline int Cost(int low, int high)
{
    --low;
    return high * (cnt[high] - cnt[low]) - (acc[high] - acc[low]);
}

void CalOriginalMatrix()
{
    for (int i = 1; i <= n2; ++i)
    {
        fill(&MatA[i][1], &MatA[i][n2 + 1], 0);
        fill(&MatB[i][1], &MatB[i][n2 + 1], 0);
    }
    for (int i = 1; i <= n2; ++i)
        for (int j = i; j <= n2 && j < i + n; ++j)
            MatB[i][j] = MatA[i][j] = Cost(i, j);
}

//Matrix multiplication with knuth optimization
void Mul(const TMatrix& x, const TMatrix& y, TMatrix& res)
{
    for (int step = 0; step < n; ++step)
        for (int i = 1; i + step < n2; ++i)
        {
            int j = i + step; //Tính res[i][i + step];
            res[i][j] = x[i][j];
            trace[i][j] = j;
            if (i == j) continue;
            int k = trace[i][j - 1];
            int endk = min(trace[i + 1][j] + 1, j);
            for (; k <= endk; ++k)
                if (Minimize(res[i][j], x[i][k] + y[k + 1][j]))
                    trace[i][j] = k;
        }
}

void Solve()
{
    int p = 1;
    while (p * 2 <= k) p *= 2;
    k %= p;
    p /= 2;
    TMatrix* b = &MatB;
    TMatrix* c = &MatC;
    for (; p > 0; k %= p, p /= 2)
    {
        Mul(*b, *b, *c);
        swap(b, c);
        if (k / p == 1)
        {
            Mul(*b, MatA, *c);
            swap(b, c);
        }
    }
    int Result = maxCost;
    for (int i = 1; i <= n; ++i)
        Minimize(Result, (*b)[i][i + n - 1]);
    WriteInt(Result);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".INP", "r", stdin);
    freopen(taskname".OUT", "w", stdout);
    ReadInput();
    CalOriginalMatrix();
    Solve();
}
