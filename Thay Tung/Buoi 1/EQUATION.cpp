#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
uint64_t a, k, res;
uint64_t pw(uint64_t x, uint64_t y) { //Solve x^y
    uint64_t r=1;
    while (y) {
        if (y%2==1) r=(r*x);
        x=(x*x);
        y=(y>>1);
    }
    return r;
}
uint64_t count_ones(uint64_t num) {
    uint64_t i=0, count=0;
    for (; i < 64; ++i) {
        if (num & 1) count++;
        num >>= 1;
    }
    return count;
}
int32_t main(void) {
    FastIO;
    freopen("EQUATION.INP","r",stdin);
    freopen("EQUATION.OUT","w",stdout);
    int T; cin>>T;
    while (T--) {
        cin>>a;
        // k=số bit 1 của a
        // res=pw(2,k);
        // k=count_ones(a); // đếm bit 1 thủ công
        k=__builtin_popcount(a); // đếm số bit 1 của a
        res=(1<<k);
        cout<<res<<endl;
    }
    return 0;
}


/* Với mỗi số a, đếm số bit 1 của a
res=2^(số bit 1 của a)
*/