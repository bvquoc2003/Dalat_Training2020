#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, k, s;
vector <long long> a, tmp;
vector <bool> mark;
vector <vector<long long> > d;
long long cost=0;
int32_t main(void) {
    FastIO;
    freopen("LOCK.INP","r",stdin);
    freopen("LOCK.OUT","w",stdout);
    cin>>n>>k>>s; a.resize(n);
    for (int i=0;i<n;i++) cin>>a[i];
    mark.resize(n,false);
    for (int pos=0;pos<n;pos++)
    if (!mark[pos]) {
        tmp.clear();
        int j=pos;
        while (!mark[j]) {
            mark[j]=true;
            tmp.push_back(a[j]);
            j+=s; j%=n;
        }
        if (tmp.empty()) continue;
        d.push_back(tmp);
    }
    n=d.size();
    for (int i=0;i<n;i++) {
        sort(d[i].begin(),d[i].end());
        long long k=d[i][(d[i].size()>>1)];
        for (int j=0;j<d[i].size();j++) cost+=abs(k-d[i][j]);
    }
    cout<<cost;
    return 0;
}