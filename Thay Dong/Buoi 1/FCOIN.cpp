#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int SIZE=100203;
vector<int> a,b;
set<int> RealCoin,Set;
int n,k;
bool f[SIZE];
void Insert1(set<int> &a, vector<int> b) {
    for (int i=0;i<b.size();++i) 
        a.insert(b[i]);
}
void Insert2(set<int> &a, vector<int> b){
    set<int> t;
    for (int i=0;i<b.size();++i){
        set<int>::iterator iter=a.find(b[i]);
        if (iter!=a.end()) t.insert(b[i]);
    }
    a.clear();
    for (set<int>::iterator iter=t.begin();iter!=t.end();++iter) a.insert(*iter);
}
int res=0;
int32_t main(void) {
    FastIO;
    freopen("FCOIN.INP","r",stdin);
    freopen("FCOIN.OUT","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=k;++i) {
        a.clear();b.clear();
        int s; cin>>s;
        for (int i=1;i<=s;++i) {
            int x; cin>>x;
            a.push_back(x);
        }
        for (int i=1;i<=s;++i) {
            int x; cin>>x;
            b.push_back(x);
        }
        cin>>s;
        if (s==0) {
            Insert1(RealCoin,a);
            Insert1(RealCoin,b);
            continue;
        }
        if (s==1) {
            Insert1(RealCoin,a);
            if (Set.size()==0)Insert1(Set,b);
            else Insert2(Set,b);
        } else {
            Insert1(RealCoin,b);
            if (Set.size()==0)Insert1(Set,a);
            else Insert2(Set,a);
        }
    }
    for (set<int>::iterator iter=RealCoin.begin();iter!=RealCoin.end();++iter) {
        set<int>::iterator it=Set.find(*iter);
        if (it!=Set.end()) Set.erase(*it);
    }
    f[0]=true;
    if (Set.size()==1) res=*Set.begin();
    else if (RealCoin.size()+1==n){
        RealCoin.insert(n+1);
        for (set<int>::iterator iter=RealCoin.begin(); iter!=RealCoin.end(); ++iter) {
            f[*iter]=true;
            if (!f[(*iter)-1]){
                res=*iter-1;
                break;
            }
        }
    }
    cout<<res;
    return 0;
}