#define taskname "GIFTS"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxA = 1e6 + 1;
char a[maxA];
int ptr[maxA];

void ReadGifts()
{
    fill(a, a + maxA, 'A');
    int m;
    cin >> m;
    while (m-- > 0)
    {
        int i;
        cin >> i;
        a[i] = 'G';
    }
    fill(ptr, ptr + maxA, 0);
}

int Solve()
{
    int res = 0;
    int n;
    cin >> n;
    while (n-- > 0)
    {
        int v;
        cin >> v;
        int q = v;
        int& p = ptr[q];
        while (v > 0 && p + q < maxA)
        {
            p += q;
            if (a[p] == 'S') continue;
            if (a[p] == 'G')
            {
                ++res;
            }
            a[p] = 'S';
            --v;
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".INP", "r", stdin);
    freopen(taskname".OUT", "w", stdout);
    ReadGifts();
    cout << Solve();
}
