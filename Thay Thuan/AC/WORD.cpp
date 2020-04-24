#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int n,k;
vector <string> a;
set <string> d;
int64_t res=0;
int32_t main(void) {
    FastIO;
    freopen("WORD.INP","r",stdin);
    freopen("WORD.OUT","w",stdout);
    cin>>n; a.resize(n);
    for (int i=0;i<n;i++) {
        string s=""; char ch;
        for (int j=0;j<n;j++) {
            cin>>ch;
            s+=ch;
        }
        a[i]=s;
    }
    cin>>k;
    for (int i=0;i<k;i++) {
        string s; cin>>s;
        d.insert(s);
    }
    for (int i=0;i<n;i++)
    for (int j=0;j<n;j++) {
        string s="";
        // cout<<i+1<<" "<<j+1<<endl;
        for (int k=j;k<n;k++) {
            s+=a[i][k];
            res+=d.count(s);
            // cout<<s<<" "<<d.count(s)<<endl;
        }
        // cout<<endl;
    }
    cout<<res;
    return 0;
}