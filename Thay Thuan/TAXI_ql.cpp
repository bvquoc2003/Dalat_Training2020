#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
void WriteInt(int x) { if (x>9) WriteInt(x/10); putchar(x%10+'0'); }
inline int ReadInt() {
	char ch;
	while (ch=getchar(), ch<'0' || ch>'9');
	int res=ch-'0';
	while (ch=getchar(), ch>='0' && ch<='9') res = res * 10 + ch - '0';
	return res;
}
typedef vector<int> vi;
int n, n0, t; vector <vi> a;
int res=INT_MAX;
vi x, save; vector <bool> cx;
bool check() {
    for (int i=1;i<=n;i++) cx[i]=true;
    for (int i=0;i<n;i++) {
        if (x[i]>n0 && cx[x[i]-n0]) return false;
        cx[x[i]]=false;
    }
    return true;
}
int32_t main(void) {
    FastIO;
    freopen("TAXI.INP","r",stdin);
    freopen("TAXI.OUT","w",stdout);
    n=ReadInt(); n0=n>>1;
    cx.resize(n+1);
    a.resize(n+1, vector <int> (n+1,0));
    for (int i=0;i<=n;i++) for (int j=0;j<=n;j++) a[i][j]=ReadInt();
    for (int i=1;i<=n;i++) x.push_back(i);
    do {
        if (!check()) continue;
        t=a[0][x[0]]+a[x[n-1]][0];
        for (int j=0;j<n-1;j++) t+=a[x[j]][x[j+1]];
        res=min(res,t);
    } while (next_permutation(x.begin(),x.end()));
    WriteInt(res);
    return 0;
}