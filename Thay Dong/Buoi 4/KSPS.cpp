#include <bits/stdc++.h>
using namespace std;
const int oo=2e6;
int n,m;
string t,s;
void Init() {
    int p=m/n, M=m%n;
    if(p==0) s=char('0');
    else while(p>0) {
        int k=p%10;
        s=char(k+'0')+s;
        p=p/10;
    }
    for(int i=1;i<=oo+4;i++) {
        s+=char(((M*10)/n)+48);
        M=(M*10)%n;
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("KSPS.INP","r",stdin);
    freopen("KSPS.OUT","w",stdout);
    cin>>m>>n>>t;
    Init();
    cout<<s.find(t)+1;
    return 0;
}