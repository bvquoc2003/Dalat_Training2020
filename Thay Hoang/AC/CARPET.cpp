/*
#linked structures, optimized cache
*/
#define taskname "CARPET"
#include <iostream>
#include <cstdio>
using namespace std;
const int maxMN = 1000 + 3;
const int maxK = 2000;

int m, n, k;
struct TNode;
typedef TNode* PNode;
struct TNode
{
    int Val;
    PNode D, R;
} Mem[maxMN * maxMN * 4];
typedef PNode TNodeBoard[maxMN][maxMN];
TNodeBoard a, b, c, d;
struct TFlip
{
    int kind;
    int x1, y1, x2, y2;
} flip[maxK];

inline int ReadInt()
{
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar());
    int x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    return x;
}

inline char ReadHV()
{
    char c;
    for (c = getchar(); c != 'H' && c != 'V'; c = getchar());
    return c;
}

void WriteInt(int x)
{
    if (x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}

void ReadInput()
{
    m = ReadInt();
    n = ReadInt();
    k = ReadInt();
    for (int i = 0; i < k; ++i)
    {
        flip[i].kind = ReadHV();
        flip[i].x1 = ReadInt();
        flip[i].y1 = ReadInt();
        flip[i].x2 = ReadInt();
        flip[i].y2 = ReadInt();
    }
}

void BuildLinks()
{
    for (int i = 0; i <= m + 1; ++i)
        for (int j = 0; j <= n + 1; ++j)
        {
            a[i][j]->R = a[i][j + 1];
            a[i][j]->D = a[i + 1][j];
            b[i][j]->R = b[i][j + 1];
            b[i][j]->D = b[i + 1][j];
            c[i][j]->R = c[i][j + 1];
            c[i][j]->D = c[i + 1][j];
            d[i][j]->R = d[i][j + 1];
            d[i][j]->D = d[i + 1][j];
        }
}

inline PNode Locate(TNodeBoard& a, int x, int y)
{
    int sx, sy;
    if (x < y)
    {
        sx = 0; sy = y;
    }
    else
    {
        sx = x; sy = 0;
    }
    PNode p = a[sx][sy];
    for (; sx < x; ++sx) p = p->D;
    for (; sy < y; ++sy) p = p->R;
    return p;
}

void Init()
{
    PNode Alloc = Mem;
    for (int i = 0; i <= m + 1; ++i)
        for (int j = 0; j <= n + 1; ++j)
        {
            a[i][j] = Alloc++;
            b[i][n + 1 - j] = Alloc++;
            c[m + 1 - i][j] = Alloc++;
            d[m + 1 - i][n + 1 - j] = Alloc++;
        }
    int cnt = 0;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            a[i][j]->Val = b[i][n + 1 - j]->Val
            = c[m + 1 - i][j]->Val = d[m + 1 - i][n + 1 - j]->Val = ++cnt;
    BuildLinks();
}

void SwapRect(PNode originP, PNode originQ, int h, int w)
{   
    PNode p, q;
    p = originP; q = originQ;
    for (int j = 1; j <= w; ++j)
    {
        p = p->R; q = q->R;
        swap(p->D, q->D);
    }
    for (int i = 1; i <= h; ++i)
    {
        p = p->D; q = q->D;
        swap(p->R, q->R);
    }
    p = originP, q =originQ;
    for (int i = 1; i <= h; ++i)
    {
        p = p->D; q = q->D;
        swap(p->R, q->R);
    }
    for (int j = 1; j <= w; ++j)
    {
        p = p->R; q = q->R;
        swap(p->D, q->D);
    }
}

void Print()
{
    PNode p = a[0][0];
    for (int i = 1; i <= m; ++i)
    {
        p = p->D;
        PNode q = p;
        for (int j = 1; j <= n; ++j)
        {
            q = q->R;
            WriteInt(q->Val);
            putchar(' ');
        }
        putchar('\n');
    }
}

void Solve()
{
    while (--k >= 0)
    {
        int h = flip[k].x2 - flip[k].x1 + 1;
        int w = flip[k].y2 - flip[k].y1 + 1;
        PNode pa = Locate(a, flip[k].x1 - 1, flip[k].y1 - 1);
        PNode pb = Locate(b, flip[k].x1 - 1, n - flip[k].y2);
        PNode pc = Locate(c, m - flip[k].x2, flip[k].y1 - 1);
        PNode pd = Locate(d, m - flip[k].x2, n - flip[k].y2);
        if (flip[k].kind == 'H')
        {
            SwapRect(pa, pb, h, w);
            SwapRect(pc, pd, h, w);
        }
        else
        {
            SwapRect(pa, pc, h, w);
            SwapRect(pb, pd, h, w);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".INP", "r", stdin);
    freopen(taskname".OUT", "w", stdout);
    ReadInput();
    Init();
    Solve();
    Print();
}
