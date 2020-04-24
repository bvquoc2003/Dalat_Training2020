#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
vector <string> save;
int64_t a, b, res=0;
int32_t main(void) {
    FastIO;
    freopen("PLUS.INP","r",stdin);
    freopen("PLUS.OUT","w",stdout);
    cin>>a>>b;
    while (!(a&1) && !(b&1)) {
        int64_t d=__gcd(a,b);
        a/=d, b/=d;
    }
    while(!(a&1)) a/=2,res++,save.push_back("B+=B");
    while(!(b&1)) b/=2,res++,save.push_back("A+=A");
    while (a!=b){
        while (!(a&1) && !(b&1)) {
            int64_t d=__gcd(a,b);
            a/=d, b/=d;
        }
        if (a==b) break;
        while(!(a&1)) a/=2,res++,save.push_back("B+=B");
        if (a==b) break;
        while(!(b&1)) b/=2,res++,save.push_back("A+=A");
        if (a==b) break;
        if (a<b) {
            save.push_back("B+=A"); 
            save.push_back("A+=A");
            b=(a>>1)+(b>>1)+((a%2)+(b%2))/2;res+=2;
        } else {
            save.push_back("A+=B");
            save.push_back("B+=B");
            a=(a>>1)+(b>>1)+((a%2)+(b%2))/2;res+=2;
        }
    }
    cout<<res<<endl;
    for (int i=0;i<res;i++) cout<<save[i]<<endl;
    return 0;
}