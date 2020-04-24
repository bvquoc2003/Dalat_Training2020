#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int res=INT_MAX;
int n; vector <int> a,b;
int32_t main(void) {
    FastIO;
    freopen("CLOCK.INP","r",stdin);
    freopen("CLOCK.OUT","w",stdout);
    cin>>n; a.resize(n+2);
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int k=0;k<12;k++) {
        b=a;
        int s=k;
        if (b[1]-k>0) b[1]-=k;
        else b[1]+=(12-k);
        for (int i=1;i<=n;i++)
        while (b[i]!=12) {
            b[i]++;
            b[i+1]--;
            s++;
            if (b[i+1]==0) b[i+1]=12; 
        }
        res=min(res,s);
    }
    cout<<res;
    return 0;
}