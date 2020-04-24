#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int k, n; string s, res="";
string Solve() {
    // cout<<s<<endl;
    while (s.length()>1) {
        string ss="";
        for (int i=1;i<s.length();i+=2) ss+=s[i];
        s=ss;
        // cout<<s<<endl;
        if (s.length()==1) break;
        ss="";
        for (int i=0;i<s.length();i+=2) ss+=s[i];
        s=ss;
        // cout<<s<<endl;
    }
    return s;
}
int32_t main(void) {
    FastIO;
    freopen("MNUM.INP","r",stdin);
    freopen("MNUM.OUT","w",stdout);
    cin>>k;
    if (k<=1000) { //Sub 1 2 3
        while (k--) {
            int n; cin>>n;
            s="";
            for (int i=1;i<=n;i++) {
                int x=i;
                string tmp="";
                while (x!=0) {
                    tmp+=char((x%10)+48);
                    x/=10;
                }
                reverse(tmp.begin(),tmp.end());
                s+=tmp;
            }
            res+=Solve();
        }
        cout<<res;
        return 0;
    }
    cout<<res;
    return 0;
}