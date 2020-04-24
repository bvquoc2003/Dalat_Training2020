#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N=100005;
// #define int long long
int n, b;
int a[N], l[N], r[N];
void Solve_L() {
    deque <int> dq;
    dq.push_back(0);
    for (int i=1;i<=n;i++) {
        while(!dq.empty() && a[dq.back()]<=a[i]) dq.pop_back();
        l[i]=dq.back();
        dq.push_back(i);
    }
}
void Solve_R() {
    deque <int> dq;
    dq.push_back(n+1);
    for (int i=n;i>=1;i--) {
        while(!dq.empty() && a[dq.back()]<a[i]) dq.pop_back();
        r[i]=dq.back();
        dq.push_back(i);
    }
}
int32_t main(void) {
    FastIO;
    freopen("NUMMAX.INP","r",stdin);
    freopen("NUMMAX.OUT","w",stdout);
    cin>>n>>b;
    for (int i=1;i<=n;i++) cin>>a[i];
    a[0]=INT_MAX; a[n+1]=INT_MAX;
    Solve_L();
    Solve_R();
    int res=0;
    for (int i=1;i<=n;i++) if (a[i]==b) res+=(i-l[i])*(r[i]-i);
    cout<<res;
    return 0;
}