#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
const int MaxN=100005;
const ll INF=1234567899876543;
struct SegmentData { ll f, sum, pre, suf; } ST[MaxN*8];
int n, T;
vector <int> a;
vector <ii> q;
void build (int id, int l, int r) {
    if (l>r) return;
    if (l==r) {
        ST[id].f=ST[id].sum=ST[id].pre=ST[id].suf=a[l];
        return;
    }
    int mi=(l+r)>>1, id1=id<<1, id2=id1+1;
    build(id1,l,mi); build(id2,mi+1,r);
    ST[id].sum=max(-INF,ST[id1].sum+ST[id2].sum);
    ST[id].f=max(-INF,max(ST[id1].f,max(ST[id2].f,ST[id1].suf+ST[id2].pre)));
    ST[id].pre=max(-INF,max(ST[id1].pre,ST[id1].sum+ST[id2].pre));
    ST[id].suf=max(-INF,max(ST[id2].suf,ST[id2].sum+ST[id1].suf));
}
void update(int id, int l, int r, int i, ll x) { // cap nhat a[i]=x
    if (l>r) return;
    if (l==r) {
        ST[id].f=ST[id].sum=ST[id].pre=ST[id].suf=x;
        return;
    }
    int mi=(l+r)>>1, id1=id<<1, id2=id1+1;
    if (i<=mi) update(id1,l,mi,i,x);
    else update(id2,mi+1,r,i,x);
    ST[id].sum=max(-INF,ST[id1].sum+ST[id2].sum);
    ST[id].f=max(-INF,max(ST[id1].f,max(ST[id2].f,ST[id1].suf+ST[id2].pre)));
    ST[id].pre=max(-INF,max(ST[id1].pre,ST[id1].sum+ST[id2].pre));
    ST[id].suf=max(-INF,max(ST[id2].suf,ST[id2].sum+ST[id1].suf));
}
int32_t main(void) {
    FastIO;
    freopen("RSEQ.INP","r",stdin);
    freopen("RSEQ.OUT","w",stdout);
    cin>>n>>T; a.resize(n+1); q.resize(T+1);
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    for (int i=1;i<=T;i++) {
        int p; cin>>p;
        update(1,1,n,p,-INF);
        cout<<ST[1].f<<endl;
    }
    return 0;
}