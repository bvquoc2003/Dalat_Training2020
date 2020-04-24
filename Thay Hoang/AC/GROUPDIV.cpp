#define taskname "GROUPDIV"
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
const int maxN = 3e5 + 1;
int n;
vector<int> a[maxN];
bool lab[maxN], InCharge[maxN];
vector<int> PList;

inline int ReadInt()
{
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar());
    int res = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        res = res * 10 + c - '0';
    return res;
}

void WriteInt(int x)
{
    if (x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}

void Enter()
{
    n = ReadInt();
    for (int i = 1; i <= n; ++i)
    {
        a[i].resize(ReadInt());
        for (int& v: a[i]) v = ReadInt();
    }
    fill(begin(lab), end(lab), false);
    fill(begin(InCharge), end(InCharge), true);
    for (int i = 1; i <= n; ++i)
        PList.push_back(i);
}

inline int ConflictCount(int x)
{
    int res = 0;
    for (int y: a[x])
        if (lab[y] == lab[x]) ++res;
    return res;
}

void Solve()
{
    while (!PList.empty())
    {
        int x = PList.back();
        PList.pop_back();
        InCharge[x] = false;
        if (ConflictCount(x) > 1)
        {
            lab[x] = !lab[x];
            for (int y: a[x])
                if (lab[y] == lab[x] && !InCharge[y])
                    PList.push_back(y);
        }
    }
    putchar('Y'); putchar('E'); putchar('S'); putchar('\n');
    for (bool g: {false, true})
    {
        for (int x = 1; x <= n; ++x)
            if (lab[x] == g)
            {
                WriteInt(x); putchar(' ');
            }
        putchar('\n');
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    Enter();
    Solve();
}
