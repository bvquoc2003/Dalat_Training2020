#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n; vector <int> a;
// void compress(vector<int> &a) {
//     set<int> s(a.begin(), a.end());
//     vector<int> b(s.begin(), s.end());
//     for (int &x: a) x=lower_bound(b.begin(),b.end(),x)-b.begin()+1;
// }
vector <int> Lmax, Rmin;
int res=0;
int32_t main(void) {
    FastIO;
    freopen("SORT.INP","r",stdin);
    freopen("SORT.OUT","w",stdout);
    cin>>n; a.resize(n+2);
    Lmax.resize(n+2); Rmin.resize(n+2); 
    Lmax[0]=INT_MIN; Rmin[n+1]=INT_MAX;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        Lmax[i]=max(Lmax[i-1],a[i]);
    }
    for (int i=n;i>=1;i--) Rmin[i]=min(Rmin[i+1],a[i]);
    for (int i=1;i<=n;i++) if (Lmax[i]<=Rmin[i+1]) res++;
    cout<<res;
    return 0;
}