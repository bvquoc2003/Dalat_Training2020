#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
long long a[4];
int32_t main() {
    FastIO;
    freopen("TRIANGLE.INP","r",stdin);
    freopen("TRIANGLE.OUT","w",stdout);
    cin>>a[1]>>a[2]>>a[3];
    sort(a+1,a+1+3);
    long long res = 0;
    if (a[1]==0) {
        a[1]=1;
        res++;
    }
    if (a[2]==0) {
        a[2]=1;
        res++;
    }
    if (a[3]==0) {
        a[3]=1;
        res++;
    }
    if (a[1]+a[2]<=a[3]) res+=(a[3]+1)-(a[1]+a[2]);
    cout<<res;
    return 0;
}