#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
string x, res="Lose";
int32_t main(void) {
    FastIO;
    freopen("COCA.INP","r",stdin);
    freopen("COCA.OUT","w",stdout);
    cin>>x;
    if(x.front()!=x.back()) res="Win";
    cout<<res;
    return 0;
}