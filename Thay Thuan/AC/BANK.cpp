#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
struct data {
    int d, t;
    data () {d=0; t=0;}
    data (int _d, int _t) {d=_d; t=_t;}
};
bool operator< (const data &x, const data &y) {return x.d<y.d;}
bool cmp(const data &x, const data &y) {return x.t>y.t;}
int n, T; vector <data> a;
priority_queue <data, vector<data> > heap;
int res=0;
int32_t main(void) {
    FastIO;
    freopen("BANK.INP","r",stdin);
    freopen("BANK.OUT","w",stdout);
    cin>>n>>T; a.resize(n+1);
    for (int i=1;i<=n;i++) cin>>a[i].d>>a[i].t;
    sort(a.begin()+1,a.end(),cmp);
    int i=1;
    while (--T>=0 && i<=n) {
        while (a[i].t>=T && i<=n) heap.push(a[i++]);
        if (!heap.empty()) {
            res+=heap.top().d;
            heap.pop();
        }
    }
    cout<<res;
    return 0;
}