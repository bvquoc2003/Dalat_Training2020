#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef pair <int,int> ii;
const int MaxN=100005;
int p[MaxN][8]; //p[i][k] vị trí người i trong ảnh k
int n; vector <int> a;
bool cmp(const int &x, const int &y) {
    int tmp=0;
    for (int k=1;k<=5;k++) if (p[x][k]<p[y][k]) tmp++;
    return (tmp>=3);
}
int32_t main(void) {
    FastIO;
    freopen("PHOTO.INP","r",stdin);
    freopen("PHOTO.OUT","w",stdout);
    cin>>n; 
    for (int k=1;k<=5;k++) 
    for (int j=1;j<=n;j++) {
        int i; cin>>i;
        p[i][k]=j;
    }
    for (int i=1;i<=n;i++) a.push_back(i);
    sort(a.begin(),a.end(),cmp);
    for (int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}