#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N=10001;
int parent[N], rnk[N], dist[N];

void init(int x){
    parent[x]=x;
    rnk[x]=0;
    dist[x]=0;
}

int Find(int x){
    if(parent[x] != x){
        int PX=parent[x];
        parent[x]=Find(PX);
        dist[x]^=dist[PX];
    }
    return parent[x];
}

void Union(int u, int v, int d){
    int PU=Find(u), PV=Find(v);
    if(rnk[PU]<rnk[PV]){
        parent[PU]=PV;
        dist[PU]=d^dist[u]^dist[v];
    }else {
        parent[PV]=PU;
        dist[PV]=d^dist[u]^dist[v];
        if(rnk[u]==rnk[v]) rnk[u]++;
    }
}
int n, Q, ans=0;
string s;
map <int, int> id;
int32_t main(void){
    FastIO;
    freopen("OD.INP","r",stdin);
    freopen("OD.OUT","w",stdout);
    cin>>n>>Q;
    int u, v, cont=0;
    bool valid=true;
    while(Q--) {
        cin>>u>>v>>s;
        if (valid){
            if (u<=0 || u>n || v<=0 || v>n || u>v) valid=false;
            else {
                u--;
                if(id.find(u)==id.end()){
                    init(cont);
                    id[u]=cont++;
                }   
                if(id.find(v)==id.end()){
                    init(cont);
                    id[v]=cont++;
                }   
                u=id[u]; v=id[v];
                int PU=Find(u), PV=Find(v), d=(s[0] == 'e'? 0 : 1);
                if(PU==PV && (dist[u]^dist[v]^d)==1) valid=false;
                else if(PU!=PV) Union(u,v,d);
                if (valid) ans++;
            }
        }
    }
    cout<<ans;
    cout<<endl;
    vector <int> a;
    for (int i=1;i<=n;i++) a.push_back(i);
    a.reserve(5);
    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
    return 0;
}