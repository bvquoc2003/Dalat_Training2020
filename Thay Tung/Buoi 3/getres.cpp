#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const string inp=".inp", out=".out", dr="res/";
string int_to_str(int x) {
    string res="";
    while (x!=0) {
        res=char((x%10)+48)+res;
        x/=10;
    }
    return res;
}
int32_t main(void) {
    freopen("res.txt","w",stdout);
    FastIO;
    int n, x; string res;
    for (int i=1;i<=42;i++) {
        string name=int_to_str(i);
        ifstream fi((dr+name+inp).c_str()); ifstream fo((dr+name+out).c_str());
        fi>>n>>x; fo>>res;
        cout<<n<<" "<<x<<" "<<res<<endl;
        fi.close(); fo.close();
    }
    return 0;
}