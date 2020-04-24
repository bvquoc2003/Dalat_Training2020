#include <bits/stdc++.h>
#define ll long long

using namespace std;

int m,n,k,t;
map <int,bool> c;
int main() {
    freopen("SPASTA.INP","r",stdin);
    freopen("SPASTA.OUT","w",stdout);
    scanf("%d%d%d%d", &m, &k, &n, &t);
    for (int i=1,x;i<=n;i++) {
        scanf("%d", &x);
        c[x]=true;
    }
    int d=0;
    ll res=0;
    for (int i=1;i<=m;i++) {
        if (!c[i]) {
            res+=(ll)t+i;
            d++;
            if (d==k) break;
        }
    }
    if (d!=k) printf("-1"); else printf("%lld", res); 
}