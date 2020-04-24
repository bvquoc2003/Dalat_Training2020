#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;

map<int,bool> exist;
map<int,bool> odd;
map<int,int> previous;

bool Union(int a, int b,  bool c){ //b>=a;
    if (!exist[b]){
        exist[b]=true;
        odd[b]=c;
        previous[b]=a;
        return true;
    }
    int i=previous[b];
    if(i==a) return (odd[b]==c);
    if(i<a) return Union(i,a-1,(c!=odd[b]));
    return Union(a,i-1,(c!=odd[b]));
};

int32_t main(void) {
    FastIO;
    freopen("OD.INP","r",stdin);
    freopen("OD.OUT","w",stdout);
    int n; cin>>n;
    int q; cin>>q;
    bool mark=false;
    int a,b; string s;
    for (int i=0;i<q;i++) {
        cin>>a>>b>>s;
        bool parity=true;
        if (s=="even") parity=false;
        if (!Union(a,b,parity) && !mark) {
            cout<<i;
            return 0;
        }
    }
    cout<<q;
    return 0;
}