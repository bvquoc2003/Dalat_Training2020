#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
inline int ReadInt() {
	char ch;
	while (ch=getchar(), ch<'0' || ch>'9');
	int res=ch-'0';
	while (ch=getchar(), ch>='0' && ch<='9') res = res * 10 + ch - '0';
	return res;
}
void WriteInt(int x) {
	if (x>9) WriteInt(x/10);
	putchar(x%10+'0');
}
int n; vector<int> a,b;
bool check() {
    for (int i=0;i<n;i++) {
        int t=a[i]+a[(i+1)%n]+a[(i+n-1)%n];
        if (t!=b[i]) return false;
    }
    return true;
}
int32_t main(void) {
    FastIO;
    freopen("CIRCLE.INP","r",stdin);
    freopen("CIRCLE.OUT","w",stdout);
    n=ReadInt(); b.resize(n);
    for (int i=0;i<n;i++) {
        b[i]=ReadInt();
        a.push_back(i+1);
    }
    if (n<=12) {
        while (!check() && next_permutation(a.begin(),a.end()));
        for (int i=0;i<n;i++) {
            WriteInt(a[i]);
            putchar(' ');
        }
        return 0;
    }
    // for (int i=0;i<n;i++) {
    //     WriteInt(a[i]);
    //     putchar(' ');
    // }
    return 0;
}