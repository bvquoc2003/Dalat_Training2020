#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, k;
long long res=0;
vector <long long> a;
bool check(long long G) {
    long long Sum=0;
    for (int i=1;i<=n;i++) Sum+=((a[i]>=G)?G:a[i]);
    return (Sum>=G*k);
}
int32_t main(void) {
    FastIO;
    freopen("GROUP0.INP","r",stdin);
    freopen("GROUP0.OUT","w",stdout);
    cin>>n>>k; a.resize(n+1);
    for (int i=1;i<=n;i++) cin>>a[i];
    long long l=0, r=n*(*max_element(a.begin()+1,a.end()));
    while (l<=r) {
        long long mid=(l+r)/2;
        if (check(mid)) {
            res=max(res,mid);
            l=mid+1;
        } else r=mid-1;
    }
    cout<<res;
    return 0;
}