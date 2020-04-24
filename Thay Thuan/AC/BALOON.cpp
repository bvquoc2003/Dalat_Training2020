#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
struct bl {
    char tp;
    int cnt;
    bl() {tp=' '; cnt=0;}
    bl(char _tp, int _cnt) {tp=_tp; cnt=_cnt;}
};
int n; string s;
int res=0;
vector <bl> a;
vector <int> x;
void TRY() {
    n=a.size(); x.clear();
    for (int i=0;i<n;i++) x.push_back(i);
    do {
        int tmp=0;
        for (int i=0;i<x.size();i++)  tmp+=a[x[i]].cnt*a[x[i]].cnt;
        res=max(res,tmp);
    } while (next_permutation(x.begin(),x.end()));
    cout<<res<<endl;
}
int32_t main(void) {
    FastIO;
    freopen("BALOON.INP","r",stdin);
    freopen("BALOON.OUT","w",stdout);
    int T; cin>>T;
    while (T--) {
        a.clear();
        string s; cin>>s;
        n=s.length();
        int i=0;
        while (i<s.length()) {
            a.push_back(bl(s[i],1));
            while (s[i]==s[i+1] && i+1<s.length()) {
                i++;
                a.back().cnt++;
            }
            i++;
        }
        TRY();
    }
    return 0;
}