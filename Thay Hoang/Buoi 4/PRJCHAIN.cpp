#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MaxN=1e5+1;
int n;
int64_t res=0;
struct data {int64_t a,b; int cs;};
data d[MaxN];
void Enter() {
    freopen ("PRJCHAIN.INP","r",stdin);
    cin>>n;
    for (int i=1; i<=n; ++i) cin>>d[i].a;
    for (int i=1; i<=n; ++i) cin>>d[i].b;
    for (int i=1; i<=n; ++i) d[i].cs=i;
}
bool cmp(data A, data B) {return min(A.a,B.b)<min(A.b,B.a);} // trả về true nếu A làm trước B
void Process() {
    sort(d+1,d+1+n,cmp);
    int64_t tmp=0;
    for (int i=1;i<=n;++i) {
        int j=d[i].cs;
        tmp-=d[i].a;
        if (tmp<0) {
            res-=tmp;
            tmp=0;
        }
        tmp+=d[i].b;
    }
}
void Print() {
    freopen("PRJCHAIN.OUT","w",stdout);
    cout<<res<<endl;
    for (int i=1;i<=n;++i) cout<<d[i].cs<<" ";
}
int32_t main() {
    FastIO;
    Enter();
    Process();
    Print();
    return 0;
}
