#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N=100005;
int n, m, k;
bool mark[N];
vector <vector <int> > ke1, ke2;
void ReadQuery(int q, vector <vector<int> > &ke) {
    int u,v;
    while (q--) {
        cin>>u>>v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
}
set <int> Set; vector <int> d; int res;
void Loang(int u, vector< vector <int> > ke) {
    mark[u]=true;
    for (int i=0;i<ke[u].size();i++) 
    if (!mark[ke[u][i]]) {
        Loang(ke[u][i],ke);
        res++;
        d.push_back(ke[u][i]);
    }
}
void DFS(int u) {
    mark[u]=true;
    for (int i=0;i<ke2[u].size();i++) 
    if (!mark[ke2[u][i]]) {
        Set.insert(ke2[u][i]);
        DFS(ke2[u][i]);
    }
}
int32_t main(void) {
    FastIO;
    freopen("SUM_CAMP.INP","r",stdin);
    freopen("SUM_CAMP.OUT","w",stdout);
    cin>>n>>m>>k;
    ke1.resize(n+1); ke2.resize(n+1);
    ReadQuery(m,ke1);
    ReadQuery(k,ke2);
    cin>>k;
    int u, v;
    while(k--) {
        char ch; cin>>ch;
        if (ch=='?') {
            Set.clear(); d.clear();
            res=0; cin>>u;
            for (int j=1;j<=n;j++) mark[j]=false;
            Loang(u,ke1);
            for (int j=1;j<=n;j++) mark[j]=false;
            DFS(u);
            for (int i=0;i<d.size();i++)
            if (!Set.count(d[i])) res--;
            cout<<res<<endl;
            continue;
        }
        if (ch=='F') {
            cin>>u>>v;
            ke2[u].push_back(v);
            ke2[v].push_back(u);
        } else {
            cin>>u>>v;
            ke1[u].push_back(v);
            ke1[v].push_back(u);
        }
    }
    return 0;
}





// #include <bits/stdc++.h>
// #define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
// // #define int long long
// using namespace std;
// const int M=100000000, N=500005;
// typedef pair <int,int> ii;
// struct query{ char c; int i; int64_t k; };
// vector <vector <int> > ke1, ke2;
// bool mark[N];
// int n, m, k, Q;
// vector <query> q;
// int par1[M], par2[M];
// void Enter() {
//     freopen("SUM_CAMP.INP","r",stdin);
//     freopen("SUM_CAMP.OUT","w",stdout);
//     cin>>n>>m>>k;ke1.resize(n+1); ke2.resize(n+1);
//     for (int i=1;i<=m;i++) {
//         int u, v;
//         cin>>u>>v;
//         ke1[u].push_back(v);
//         ke1[v].push_back(u);
//     }
//     for (int i=1;i<=k;i++) {
//         int u, v;
//         cin>>u>>v;
//         ke2[u].push_back(v);
//         ke2[v].push_back(u);
//     }
//     cin>>k; q.resize(k);
//     for (int i=0;i<k;i++) {
//         cin>>q[i].c>>q[i].i;
//         if (q[i].c!='?') cin>>q[i].k;
//     }
// }
// void DFS(int u, vector<vector<int> > ke, int par[]) {
//     mark[u]=true;
//     if (ke[u].empty()) return;
//     for (int i=0;i<ke[u].size();i++) 
//     if (!mark[ke[u][i]]) {
//         DFS(ke[u][i],ke,par);
//         par[ke[u][i]]=u;
//     }
// }
// void Init() {
//     for (int i=1;i<=n;i++) par1[i]=-1;
//     for (int i=1;i<=n;i++) mark[i]=false;
//     for (int i=1;i<=n;i++)
//     if (!mark[i]) DFS(i,ke1,par1);
//     for (int i=1;i<=n;i++) par2[i]=-1;
//     for (int i=1;i<=n;i++) mark[i]=false;
//     for (int i=1;i<=n;i++)
//     if (!mark[i]) DFS(i,ke2,par2);
// }
// int res; vector<int> tmp;
// int Root(int x, int par[]) {
//     if (par[x]==-1) return x;
//     return Root(par[x],par);
// }
// void Union(int u, int v, int par[]) {
//     int a=Root(u,par), b=Root(v,par);
//     if (a==b) return;
//     if (u>v) swap(u,v);
//     par[u]=v;
// }
// bool check(int x, int y) {
//     int a=Root(x,par2), b=Root(y,par2);
//     return a==b;
// }
// void Loang(int u, vector< vector <int> > ke) {
//     mark[u]=true;
//     for (int i=0;i<ke[u].size();i++) 
//     if (!mark[ke[u][i]]) {
//         Loang(ke[u][i],ke);
//         res++;
//         tmp.push_back(ke[u][i]);
//     }
// }
// void Count(int x) {
//     for (int i=1;i<=n;i++) mark[i]=false;
//     Loang(x,ke1);
// }
// int32_t main(void) {
//     Enter();
//     Init();
//     // for (int i=1;i<=n;i++) cout<<par2[i]<<endl;
//     for (int i=0;i<k;i++) {
//         if (q[i].c=='T') {
//             Union(q[i].i,q[i].k,par1);
//             ke1[q[i].i].push_back(q[i].k);
//             ke1[q[i].k].push_back(q[i].i);
//         }
//         else if (q[i].c=='F') {
//             Union(q[i].i,q[i].k,par2);
//             ke2[q[i].i].push_back(q[i].k);
//             ke2[q[i].k].push_back(q[i].i);
//         }
//         else {
//             tmp.clear(); res=0;
//             Count(q[i].i);
//             for (int j=0;j<tmp.size();j++) 
//                 if (!check(q[i].i,tmp[j])) res--;
//             cout<<res<<endl;
//         }
//     }
//     return 0;
// }