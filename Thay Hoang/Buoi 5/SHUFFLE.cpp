#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N=1e5+2;
struct query {
    int i, m, j;
    query () {i=0;m=0;j=0;}
    query (int _i, int _m, int _j) {i=_i; m=_m; j=_j;}
} q[N];
int Undo(int p, query q) {
    int i=q.i, m=q.m, j=q.j;
    int p1, p2, p3;
    if (i<=j) {
        p1=i-1;
        p2=m;
        p3=j-i;
    }
    else {
        p1=j-1;
        p2=i-j;
        p3=m;
    }
    if (p<=p1) return p;
    if (p<=p1+p3) return p+p2;
    if (p<=p1+p2+p3) return p-p3;
    return p;
}
int32_t main() {
    FastIO;
    freopen("SHUFFLE.INP","r",stdin);
    freopen("SHUFFLE.OUT","w",stdout);
    int n, k, x;
    cin>>n>>k>>x;
    for (int i=1;i<=x;i++) cin>>q[i].i>>q[i].m>>q[i].j;
    for (int i=1;i<=k;i++) {
        int p=i;
        for (int j=x;j>=1;j--) p=Undo(p,q[j]);
        cout<<p<<" ";
    }
    return 0;
}