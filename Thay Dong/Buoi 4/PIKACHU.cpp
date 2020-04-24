#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N=1001;
int m, n, a[N][N];
void Subtask1() {
    int cnt0=0;
    for (int i=1;i<=m;i++) for (int j=1;j<=n;j++) {
        cin>>a[i][j];
        if (a[i][j]==0) cnt0++;
    }
    if (cnt0==4) {
        cout<<"0";
        return;
    }
    if (a[1][1]!=0 && (a[1][1]==a[1][2] || a[1][1]==a[2][1])) {
        cout<<"1";
        return;
    }
    if (a[2][2]!=0 && (a[2][2]==a[1][2] || a[1][1]==a[2][1])) {
        cout<<"1";
        return;
    }
    cout<<"4";
}
int32_t main(void) {
    FastIO;
    freopen("PIKACHU.INP","r",stdin);
    freopen("PIKACHU.OUT","w",stdout);
    cin>>m>>n;
    if (m==2 && n==2) {
        Subtask1();
        return 0;
    }
    return 0;
}