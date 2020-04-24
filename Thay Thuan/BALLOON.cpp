#include <bits/stdc++.h>

using namespace std;
#define INF 1000000007
string s;
int Solve(string s) {
    if (s.length()==0) return 0;
    if (s.length()==1) return -INF;
    int res=-INF;
    for (int i=0; i<s.size(); i++) 
        if (i==0 || s[i]!=s[i-1]) {
            int j=i;
            while (j < s.size() && s[j]==s[i]) j++;
            if (j-i>=2) {
                string t=s.substr(0,i)+s.substr(j,s.size());
                res=max(res,(j-i)*(j-i)+Solve(t));
            }
        }
    return res;
}

int32_t main(void) {
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int T; cin>>T;
    while (T--) {
        cin>>s;
        int r=Solve(s);
        cout<<((r<=0)?(0):(r))<<endl;
    }
    return 0;
}
