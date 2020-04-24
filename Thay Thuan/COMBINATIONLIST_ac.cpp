#include<bits/stdc++.h>
using namespace std;

#define y1 as214
#define ii pair < int , int >
#define iii pair < int , ii >
#define iv pair < ii , ii >

#define fi first
#define se second
#define fr front()
#define pb push_back


#define FOR(i , x , n) for(ll i = x ; i <= n ; ++i)
#define REP(i , n) for(ll i = 0 ; i < n ; ++i)
#define FORD(i , x , n) for(ll i = x ; i >= n ; --i)

#define ll long long
#define oo 1e10
#define int long long
#define eps 1e-8

const int N = 1e4 + 5;
int n , m , k;
int C[N][N] , ans[N];
set < int > s;

main()
{
    //freopen("COMBINATIONLIST.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    int x = m;
    C[0][0] = 1;
    FOR(i , 1 , n)
    {
        C[i][0] = 1;
        C[i][1] = i;
        for(int j = 2 ; j <= min(i , m) ; j++)
        {
            if(C[i - 1][j - 1] + C[i - 1][j] <= k)
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            else
                C[i][j] = 1e10;
        }
    }
    FOR(i , 1 , n)
        s.insert(i);
    k--;


    while(true)
    {
        m--;
        if(s.empty())
            break;
        auto it = s.begin();
        ans[m + 1] = *(it);

        int res = 0;
        while(true)
        {
            if(C[n - *(it)][m] <= k)
            {
                k -= C[n - (*it)][m];
                auto it1 = it;
                it1++;
                if(it1 != s.end())
                    ans[m + 1] = (*it1);
                else
                {
                    cout << "-1";
                    exit(0);
                }
                s.erase(it);
            }
            else
            {
                s.erase(it);
                break;
            }
            if(s.empty())
                break;
            it = s.begin();
        }
        if(m == 0)
            break;
    }
    if(k != 0)
        cout << "-1";
    else
    {
        FORD(i , x , 1)
            cout << ans[i] << " ";
    }
}
