#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll maxn = 300001;

ll n;
ll a[maxn];
queue<ll>q;

int main() {
    // freopen("input.txt", "r", stdin);
    freopen("union.inp", "r", stdin);
    freopen("union.out", "w", stdout);
    
    cin>>n;
    for (ll i=1;i<=n;i++) scanf("%lld", &a[i]);

    sort(a+1, a+n+1);

    ll res=0, tr=n, x;
    while (tr+q.size()>1) {
        while (tr>1 && a[tr]==a[tr-1]) tr--;

        if (tr>0 && !q.empty() && a[tr]==q.front()) 
            { x=a[tr--]; q.pop(); }
        else if (q.empty() || (tr>0 && a[tr]>q.front())) 
            { x=a[tr--]; }
        else if (tr==0 || (!q.empty() && q.front()>a[tr])) 
            { x=q.front(); q.pop(); }
        else continue;
        if (x == 1) break;
        res++;
        if (q.empty() || q.back()!=x/2) q.push(x/2); 
    }

    cout << res;

    return 0;
}