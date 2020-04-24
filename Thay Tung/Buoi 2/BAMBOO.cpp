#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int n,m;
char a[311][311];
int go[311][311][5];
bool visited[311][311][5];
int dx[5] = {0,-1,0,1,0};
int dy[5] = {0,0,1,0,-1};
void init() {
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
    if (a[i][j] == '.')
        for (int k=1;k<=4;k++)
        {
            go[i][j][k] = 1;
            int xx = i + dx[k];
            int yy = j + dy[k];
            while(1 <= xx && xx <= n && 1 <= yy && yy <= m && a[xx][yy] == '.')
            {
                xx += dx[k];
                yy += dy[k];
                go[i][j][k]++;
            }
        }
}
bool check(int z)
{
    //cerr << z << '\n';
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            for (int k=1;k<=4;k++)
                visited[i][j][k] = false;
    queue<iii> CurrList;
    for (int i=1;i<=n;i++)
    {
        // cerr << i << ' ' << go[i][1][3] << ' ' << go[i][1][1] << '\n';
        if (go[i][1][3] >= z)
        {
            CurrList.push(iii(3,ii(i,1)));
            visited[i][1][3] = true;
        }
        if (go[i][1][1] >= z)
        {
            CurrList.push(iii(1,ii(i,1)));
            visited[i][1][1] = true;
        }
    }
    while(!CurrList.empty())
    {
        int t = CurrList.front().first;
        int x = CurrList.front().second.first;
        int y = CurrList.front().second.second;
        //cerr << x << ' ' << y << ' ' << t << '\n';
        CurrList.pop();
        if (y == m && (t == 1 || t == 3)) return true;
        // Here comes the dumb shit
        if (t == 1)
        {
            if (x - z >= 1 && a[x - z][y] == '.' && !visited[x-1][y][t])
            {
                visited[x-1][y][t] = true;
                CurrList.push(iii(t,ii(x-1,y)));
            }
            if (x + 1 <= n && a[x + 1][y] == '.' && !visited[x+1][y][t])
            {
                visited[x+1][y][t] = true;
                CurrList.push(iii(t,ii(x+1,y)));
            }
            if (go[x-z+1][y][2] >= z && !visited[x-z+1][y][2])
            {
                visited[x-z+1][y][2] = true;
                CurrList.push(iii(2,ii(x-z+1,y)));
            }
            if (go[x-z+1][y][4] >= z && !visited[x-z+1][y][4])
            {
                visited[x-z+1][y][4] = true;
                CurrList.push(iii(4,ii(x-z+1,y)));
            }
            if (go[x][y][2] >= z && !visited[x][y][2])
            {
                visited[x][y][2] = true;
                CurrList.push(iii(2,ii(x,y)));
            }
            if (go[x][y][4] >= z && !visited[x][y][4])
            {
                visited[x][y][4] = true;
                CurrList.push(iii(4,ii(x,y)));
            }
        }
        else if (t == 2)
        {
            if (y + z <= m && a[x][y + z] == '.' && !visited[x][y+1][t])
            {
                visited[x][y+1][t] = true;
                CurrList.push(iii(t,ii(x,y+1)));
            }
            if (y - 1 >= 1 && a[x][y - 1] == '.' && !visited[x][y-1][t])
            {
                visited[x][y-1][t] = true;
                CurrList.push(iii(t,ii(x,y-1)));
            }
            if (go[x][y+z-1][1] >= z && !visited[x][y+z-1][1])
            {
                visited[x][y+z-1][1] = true;
                CurrList.push(iii(1,ii(x,y+z-1)));
            }
            if (go[x][y+z-1][3] >= z && !visited[x][y+z-1][3])
            {
                visited[x][y+z-1][3] = true;
                CurrList.push(iii(3,ii(x,y+z-1)));
            }
            if (go[x][y][1] >= z && !visited[x][y][1])
            {
                visited[x][y][1] = true;
                CurrList.push(iii(1,ii(x,y)));
            }
            if (go[x][y][3] >= z && !visited[x][y][3])
            {
                visited[x][y][3] = true;
                CurrList.push(iii(3,ii(x,y)));
            }
        }
        else if (t == 3)
        {
            if (x + z <= n && a[x + z][y] == '.' && !visited[x+1][y][t])
            {
                visited[x+1][y][t] = true;
                CurrList.push(iii(t,ii(x+1,y)));
            }
            if (x - 1 >= 1 && a[x - 1][y] == '.' && !visited[x-1][y][t])
            {
                visited[x-1][y][t] = true;
                CurrList.push(iii(t,ii(x-1,y)));
            }
            if (go[x+z-1][y][2] >= z && !visited[x+z-1][y][2])
            {
                visited[x+z-1][y][2] = true;
                CurrList.push(iii(2,ii(x+z-1,y)));
            }
            if (go[x+z-1][y][4] >= z && !visited[x+z-1][y][4])
            {
                visited[x+z-1][y][4] = true;
                CurrList.push(iii(4,ii(x+z-1,y)));
            }
            if (go[x][y][2] >= z && !visited[x][y][2])
            {
                visited[x][y][2] = true;
                CurrList.push(iii(2,ii(x,y)));
            }
            if (go[x][y][4] >= z && !visited[x][y][4])
            {
                visited[x][y][4] = true;
                CurrList.push(iii(4,ii(x,y)));
            }
        }
        else if (t == 4)
        {
            if (y - z >= 1 && a[x][y - z] == '.' && !visited[x][y-1][t])
            {
                visited[x][y-1][t] = true;
                CurrList.push(iii(t,ii(x,y-1)));
            }
            if (y + 1 <= m && a[x][y + 1] == '.' && !visited[x][y+1][t])
            {
                visited[x][y+1][t] = true;
                CurrList.push(iii(t,ii(x,y+1)));
            }
            if (go[x][y-z+1][1] >= z && !visited[x][y-z+1][1])
            {
                visited[x][y-z+1][1] = true;
                CurrList.push(iii(1,ii(x,y-z+1)));
            }
            if (go[x][y-z+1][3] >= z && !visited[x][y-z+1][3])
            {
                visited[x][y-z+1][3] = true;
                CurrList.push(iii(3,ii(x,y-z+1)));
            }
            if (go[x][y][1] >= z && !visited[x][y][1])
            {
                visited[x][y][1] = true;
                CurrList.push(iii(1,ii(x,y)));
            }
            if (go[x][y][3] >= z && !visited[x][y][3])
            {
                visited[x][y][3] = true;
                CurrList.push(iii(3,ii(x,y)));
            }
        }
    }
    return false;
}
int32_t main(void) 
{
    FastIO;
    freopen("BAMBOO.INP","r",stdin);
    freopen("BAMBOO.OUT","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        string s;
        cin >> s;
        for (int j=0;j<s.size();j++)
            a[i][j+1] = s[j];
    }
    init();
    if (m == 1) // special cases
    {
        int res = 0;
        for (int i=1;i<=n;i++) res = max(res,go[i][1][3]);
        cout << res;
        return 0;
    }
    //cerr << "DONE INIT\n";
    int l = 0, r = min(n,m);
    int ans = 0;
    while (l <= r) // Binary Search to optimize time i guess :P
    {
        int mi = (l+r)/2;
        if (check(mi))
        {
            ans = mi;
            l = mi + 1;
        }
        else r = mi - 1;
    }
    cout << ans;
    return 0;
}