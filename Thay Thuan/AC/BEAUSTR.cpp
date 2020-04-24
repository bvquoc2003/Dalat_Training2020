#include <bits/stdc++.h>
using namespace std;
int m,n;
vector <int> a, s, p;
int res=0;

int ChgK(int x) {
    int re=0;
    for (int i=1;i<=n;)
        if (s[i]>=x && p[s[i]-x]!=0) {
            i=p[s[i]-x];
            if (a[i]==1) re++;
        }
        else {
            if (a[i]==1)  re--;
            break;
        }
    return re;
}

int32_t main(void) {
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("BEAUSTR.INP","r",stdin);
    freopen("BEAUSTR.OUT","w",stdout);
    cin>>n;
    a.resize(n+2); s.resize(n+2); p.resize(n+2);
    for (int i=1;i<=n;i++) {
        char ch; cin>>ch;
        a[i]=ch-'0';
        if (a[i]==1) res++;
    }
    p[0]=n+1;
    for (int i=n;i>=1;i--) {
        s[i]=s[i+1]; if (a[i]==0) s[i]++;
        if (a[i]==1) p[s[i]]=i;
        else p[s[i]]=p[s[i+1]];
    }
    for (int i=1;i<=n/2;i++) {
        int k=ChgK(i);
        if (k) res=max(res,i*(k+1)+k);
    }
    cout<<res;
    return 0;
}