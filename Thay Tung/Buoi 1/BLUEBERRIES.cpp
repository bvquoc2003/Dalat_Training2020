#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, k, ans;
int32_t main(void) {
    FastIO;
    freopen("BLUEBERRIES.INP","r",stdin);
    freopen("BLUEBERRIES.OUT","w",stdout);
    cin>>n>>k;
    ans=(n+k-1)/k;
    if (k!=n && n<2*k) ans++;
    cout<<ans;
    cout<<endl;
    for (int i=-10;i<=10;i++) cout<<i<<" "<<(i^3)<<endl;
    return 0;
}

// (n%k==0) res=n/k;
// (n>2k) res=ceil(n/k);
// (n<2k) res=ceil(n/k)+1;

// ans=(n+k-1)/k;
// if (k!=n && n<2*k) ans++;
