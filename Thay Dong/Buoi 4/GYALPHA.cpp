#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef long long ll;
const int N=5555;
int n, m, cnt[N], d[N][N];
vector<ll> ke[N];
string s;
queue <ll> q;
void bfs(ll u){
    for (int i=1;i<=n;i++) cnt[i]=0;
    q.push(u);
    while (q.size()>0){
        ll v=q.front();q.pop();
        if (s[u]!=s[v] && cnt[v]<3) {
            d[u][v]++;
            cnt[v]++;
            q.push(v);
            continue;
        }
        for (int i=0; i<ke[v].size();i++){
            if (d[u][ke[v][i]]) continue;
            d[u][ke[v][i]]=d[u][v]+1;
            q.push(ke[v][i]);
        }
    }
}
int32_t main(void) {
    FastIO;
    freopen("GYALPHA.INP","r",stdin);
    freopen("GYALPHA.OUT","w",stdout);
    cin>>n>>m;
    cin>>s; s=" "+s;
    for (int i=1;i<=m;i++) {
        int u,v; cin>>u>>v;
        ke[u].push_back(v); ke[v].push_back(u);
    }
    for (int i=1;i<=n;i++) bfs(i);
    ll G=0, Y=0;
    for (int i=1;i<=n;i++) 
    if (s[i]=='G') for (int j=i+1;j<=n;j++) if (s[j]=='G') G+=d[i][j];
    for (int i=1;i<=n;i++) 
    if (s[i]=='Y') for (int j=i+1;j<=n;j++) if (s[j]=='Y') Y+=d[i][j];
    cout<<G<<" "<<Y;
    return 0;
}
