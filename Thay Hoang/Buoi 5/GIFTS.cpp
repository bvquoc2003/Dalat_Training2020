#include <bits/stdc++.h>

using namespace std;
const int N=1000005;
int m, n, Max=0, b[N];
bool mark[N];
int res;
int32_t main() {
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("GIFTS.INP","r",stdin);
    freopen("GIFTS.OUT","w",stdout);
    cin>>m;
    for (int i=1;i<=m;i++) {
        cin>>b[i];
        Max=max(Max,b[i]);
    }
    cin>>n; res=m;
    for (int i=1,x;i<=n;i++) {
        cin>>x;
        int j=0, k=x;
        while (x<=Max && j<k) {
            if (!mark[x]) {
                mark[x]=true;
                j++;
            }
            x+=k;
        }
    }
    for (int i=1;i<=m;i++) if (!mark[b[i]]) res--;
    cout<<res;
}