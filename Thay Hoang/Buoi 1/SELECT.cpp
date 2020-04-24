#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define ans getmax(1,1,spt,1,spt)
using namespace std;
template <typename T>
inline void Read(T& x) {
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}
template <typename T>
inline void Write(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}

const int M=100000000, N=500005;
typedef pair <int,int> ii;
struct query{ char c; int i; int64_t k;};
vector <ii> e; //edges
vector <int64_t> a; //Trong so
vector <vector <int> > ke;
bool del[N], mark[N];
int n, m, q;
vector <query> Q;
int spt=0, par[M];
int64_t ST[8*N], tplt[N];
void Enter() {
    freopen("SELECT.INP","r",stdin);
    freopen("SELECT.OUT","w",stdout);
    Read(n); Read(m); Read(q);
    a.resize(n+5);
    for (int i=1;i<=n;i++) Read(a[i]);
    e.resize(m+1); ke.resize(n+1); Q.resize(q);
    for (int i=1;i<=m;i++) {
        Read(e[i].first);
        Read(e[i].second);
    }
    for (int i=1;i<=n;i++) mark[i]=false;
    for (int i=1;i<=m;i++) del[i]=false;
    for (int i=0;i<q;i++) {
        cin>>Q[i].c;
        Read(Q[i].i);
        if (Q[i].c=='C') {
            Read(Q[i].k);
            swap(Q[i].k,a[Q[i].i]);
        } else del[Q[i].i]=true;
    }
    reverse(Q.begin(),Q.end());
    // Dua bai toan tu xoa canh thanh them canh
    for (int i=1;i<=m;i++)
    if (!del[i]) {
        ke[e[i].first].push_back(e[i].second);
        ke[e[i].second].push_back(e[i].first);
    }
}
void update(int id, int l, int r, int i, int64_t v) { //Cap nhat tplt[i]=v
    if (i < l || r < i) return;
    if (l==r) {
        ST[id]=v;
        tplt[i]=v;
        return;
    }
    int mid=(l+r)/2, id1=id*2, id2=(id*2)+1;
    update(id1,l,mid,i,v);
    update(id2,mid+1,r,i,v);
    ST[id]=max(ST[id1],ST[id2]);
}
int getmax(int id, int l, int r, int u, int v) {
    if (v < l || r < u) return INT_MIN;
    if (u <= l && r <= v) return ST[id];
    int mid = (l+r)/2, id1=id*2, id2=(id*2)+1;
    return max(getmax(id1,l,mid,u,v), getmax(id2, mid+1, r, u, v));
}
void DFS(int u) {
    mark[u]=true;
    if (par[u]==0) par[u]=spt+N;
    tplt[spt]+=a[u];
    if (ke[u].empty()) return;
    for (int i=0;i<ke[u].size();i++) 
    if (!mark[ke[u][i]]) {
        DFS(ke[u][i]);
        par[ke[u][i]]=u;
    }
}
void Init() {
    for (int i=1;i<=n;i++)
    if (!mark[i]) {
        tplt[++spt]=0;
        DFS(i);
    }
    for (int i=1;i<=spt;i++) update(1,1,spt,i,tplt[i]);
}
int Find(int x) {
    if (par[x]<N) return Find(par[x]);
    return par[x];
}
int Root(int x) {
    if (par[x]<N) return Root(par[x]);
    return x;
}
void Union(int u, int v) {
    int a=Find(u), b=Find(v);
    if (a==b) return;
    if (u>v) {
        par[Root(u)]=v;
        tplt[b-N]+=tplt[a-N];
        update(1,1,spt,b-N,tplt[b-N]);
        update(1,1,spt,a-N,-1);
    }
    else {
        par[Root(v)]=u;
        tplt[a-N]+=tplt[b-N];
        update(1,1,spt,a-N,tplt[a-N]);
        update(1,1,spt,b-N,-1);
    }
}
void UpdateW(int pos, int64_t val) {
    int i=Find(pos)-N;
    tplt[i]-=a[pos];
    tplt[i]+=val;
    a[pos]=val;
    update(1,1,spt,i,tplt[i]);
}
vector<int> res;
int32_t main(void) {
    Enter();
    Init();
    for (int i=0;i<q;i++) {
        res.push_back(ans);
        if (Q[i].c=='D') Union(e[Q[i].i].first,e[Q[i].i].second);
        else UpdateW(Q[i].i,Q[i].k);
    }
    reverse(res.begin(),res.end());
    for (int i=0;i<res.size();i++) {
        Write(res[i]);
        putchar('\n');
    }
    return 0;
}