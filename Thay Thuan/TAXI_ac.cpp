#include<bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
void WriteInt(int x) { if (x>9) WriteInt(x/10); putchar(x%10+'0'); }
inline int64_t ReadInt() {
	char ch;
	while (ch=getchar(), ch<'0' || ch>'9');
	int res=ch-'0';
	while (ch=getchar(), ch>='0' && ch<='9') res = res * 10 + ch - '0';
	return res;
}
const int MaxN=505;

int n, n0;
int64_t a[MaxN][MaxN], f[21][1<<21];

int64_t dp(int64_t pos, int64_t bitmask) {
	if (bitmask==(1<<n)-1) return a[pos][0];
	if (f[pos][bitmask]!=-1) return f[pos][bitmask];
	f[pos][bitmask]=__LONG_LONG_MAX__;
	for (int64_t i=0;i<n;i++) {
		if (bitmask & (1<<i)) continue;
		if (i-n0>=0) {
			if (bitmask & (1<<(i-n0))) { f[pos][bitmask]=min(f[pos][bitmask], dp(i,bitmask | (1 << i))+a[pos][i]); }
		} else f[pos][bitmask]=min(f[pos][bitmask], dp(i,bitmask | (1<<i))+a[pos][i]);
	}
	return f[pos][bitmask];
}

int32_t main(void) {
	FastIO;
	freopen("TAXI.INP","r",stdin);
	freopen("TAXI.OUT","w",stdout);
	n=ReadInt(); n0=n>>1;
	memset(f,-1, sizeof(f));
	for (int i=0;i<=n;i++) for (int j=0;j<=n;j++) a[i][j]=ReadInt(); n++;
	WriteInt(dp(0,1));
	return 0;
}