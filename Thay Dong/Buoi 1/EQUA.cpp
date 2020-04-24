#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
struct pt {int a, b, c;};
int n; vector <pt> d;
set <double> save;
int res=0;
void Solve(int a, int b, int c) {
    if (a==0) {
        if (b==0 && c==0) {
            res=-1;
            return;
        }
        if (b==0 && c!=0) return;
        save.insert((double)-c/b);
        return;
    }
    double delta=(double)b*b-4.0*a*c;
    double x1, x2;
    if(delta<0) return;
    else {
        delta=sqrt(delta);
        x1=(double)(-b+delta)/(2.0*a);
        x2=(double)(-b-delta)/(2.0*a);
        save.insert(x1);
        save.insert(x2);
    }
}
int32_t main(void) {
    FastIO;
    freopen("EQUA.INP","r",stdin);
    freopen("EQUA.OUT","w",stdout);
    cin>>n; d.resize(n+1);
    for (int i=1;i<=n;i++) cin>>d[i].a>>d[i].b>>d[i].c;
    for (int i=1;i<=n;i++) {
        if (res==-1) break;
        Solve(d[i].a,d[i].b,d[i].c);
    }
    if (res!=-1) res=save.size();
    cout<<res;
    return 0;
}