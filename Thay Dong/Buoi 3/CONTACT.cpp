#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;

const int N=(int)1e5+1;
const int64_t base=1000000007;

int cha[N];
int n,m,h;
int p,q,l;

int find(int x) {
    if (cha[x]!=x) cha[x]=find(cha[x]);
    return cha[x];
}
int64_t POW(int a, int n) {
    if(n==1) return a;
    else {
        int64_t temp=POW(a,n/2)%base;
        if(n%2==0) return (temp*temp)%base;
        else return (temp*temp*a)%base;
    }
}
int32_t main(void) {
    FastIO;
    freopen("CONTACT.INP","r",stdin);
    freopen("CONTACT.OUT","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cha[i]=i;
    h=n;
    for (int i=1;i<=m;i++) {
        cin>>p>>q>>l;
        for (int j=1;j<=l;j++) {
            int u=find((p+j-1));
            int v=find((q+j-1));
            if (u!=v) {
                cha[u]=cha[v];
                h--;
            }
        }
    }
    int64_t res=POW(2,h)%base;
    cout<<res;
    return 0;
}


