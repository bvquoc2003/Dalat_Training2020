#define taskname "SEATING"
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;
const int maxN = 1e5 + 1;
int n, k;
struct TEvent
{
    int time;
    int idx;
    inline bool operator < (const TEvent& other) const
    {
        return time < other.time;
    }
} event[2 * maxN];
int Prev[maxN + 1], Next[maxN + 1], Pos[maxN + 1];
bool InRoom[maxN + 1];

struct TSpace
{
    int ibegin, iend;
    inline bool Valid() const
    {
        return InRoom[ibegin] && InRoom[iend];
    }
    inline bool operator < (const TSpace& other) const
    {
        int temp = (Pos[iend] - Pos[ibegin]) - (Pos[other.iend] - Pos[other.ibegin]);
        if (temp != 0) return temp < 0;
        else return Pos[ibegin] > Pos[other.ibegin];
    }
};
priority_queue<TSpace> PQ;

void ReadInput()
{
    ifstream fi(taskname".INP");
    fi >> k >> n;
    for (int i = 1; i <= n; ++i)
    {
        int a, b;
        fi >> a >> b;
        event[i * 2 - 1] = {a, i};
        event[i * 2] = {b, -i};
    }
    sort(event + 1, event + 2 * n + 1);
    fi.close();
}

inline void Link(int i, int j)
{
    Prev[j] = i;
    Next[i] = j;
}

void Init()
{
    fill(InRoom + 1, InRoom + n + 1, false);
    InRoom[0] = InRoom[n + 1] = true;
    Pos[0] = 0;
    Pos[n + 1] = k + 1;
    Link(0, n + 1);
    PQ.push({0, n + 1});
}

void Add(int idx)
{
    while (!PQ.top().Valid()) PQ.pop();
    TSpace Space = PQ.top();
    PQ.pop();
    Pos[idx] = (Pos[Space.ibegin] + Pos[Space.iend]) / 2;
    InRoom[idx] = true;
    PQ.push({Space.ibegin, idx});
    PQ.push({idx, Space.iend});
    Link(Space.ibegin, idx);
    Link(idx, Space.iend);
}

void Remove(int idx)
{
    PQ.push({Prev[idx], Next[idx]});
    Link(Prev[idx], Next[idx]);
    InRoom[idx] = false;
}

void Solve()
{
    for (int i = 1; i <= 2 * n; ++i)
        if (event[i].idx > 0)
            Add(event[i].idx);
        else
            Remove(-event[i].idx);
}

void Print()
{
    ofstream fo(taskname".OUT");
    for (int i = 1; i <= n; ++i)
        fo << Pos[i] << ' ';
    fo.close();
}

int main()
{
    ReadInput();
    Init();
    Solve();
    Print();
}
