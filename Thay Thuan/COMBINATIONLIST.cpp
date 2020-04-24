#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
const int MaxN=10505;
bool ok=false;
int n, m, k, cnt=0;
vector <int> x;
vector <bool> cx;
void Try(int i) {
    for (int j=x[i-1]+1;j<=n;j++) {
        if (!ok && cx[j]) {
            x[i]=j;
            if (i==m) {
				cnt++;
				if (cnt==k) {
					ok=true;
					for (int l=1;l<=m;l++) printf("%d ",x[l]);
					return;
				}
            } else {
                cx[j]=false;
                Try(i+1);
                cx[j]=true;
            }
        }
    }
}
int32_t main(void) {
	FastIO;
	freopen("COMBINATIONLIST.INP","r",stdin);
	freopen("COMBINATIONLIST.OUT","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	if (m==n && k>1) {
		printf("-1");
		return 0;
	} 
	x.resize(m+1);
	cx.resize(n+1,true);
	Try(1);
	if (!ok) printf("-1");
	return 0;
}