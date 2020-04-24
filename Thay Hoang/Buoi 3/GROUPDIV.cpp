#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;

const int N=500505;

int n, gr[N];
queue <int> qu;
vector <int> res[102], h[N];

int get(int u){
    int res=0;
    for (int i=0;i<h[u].size();i++) 
        if (gr[u]==gr[h[u][i]]) res++;
    return res;
}

int32_t main(void) {
    FastIO;
    freopen("GROUPDIV.INP","r",stdin);
    freopen("GROUPDIV.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++){
        int t,x; cin>>t;
        for (int j=1;j<=t;j++) {
            cin>>x;
            h[i].push_back(x);
        }
        gr[i]=1;
    }
    for (int i=1;i<=n;i++) qu.push(i);
    while (qu.size()>0) {
        int t=qu.front();qu.pop();
        if (get(t)>=2) {
            gr[t]=(gr[t]+1)%2;
            for (int i=0;i<h[t].size();i++) 
                if (get(h[t][i])>=2) qu.push(h[t][i]);
        }

    }
    for (int i=1;i<=n;i++) res[gr[i]].push_back(i);
    cout<<"YES\n";
    for (int i=0;i<res[0].size();i++) cout<<res[0][i]<<" "; cout<<"\n";
    for (int i=0;i<res[1].size();i++) cout<<res[1][i]<<" "; cout<<"\n";
    return 0;
}
