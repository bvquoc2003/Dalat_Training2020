#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int BASE=31, MaxN=500505;
int n; string s;
int64_t pw[MaxN], H[MaxN], hss[MaxN];
vector<int> save;
void Cal_Hash() {
    pw[0]=1;
	for(int i=1;i<MaxN;i++) pw[i]=int64_t(pw[i-1]*BASE);
    for(int i=1;i<=n;i++) H[i]=s[i-1]-'a'+H[i-1]*BASE+1;
}
bool kARR(int k){
	string ss = "";
	for(int i=0;i<k;i++) ss+=s[i]; ss+=ss;
	for(int i=1;i<=k*2;i++) hss[i]=ss[i-1]-'a'+hss[i-1]*BASE+1;
	for(int i=0;i<n;i+=k){
		int64_t get_hash=H[i+k]-H[i]*pw[k];
		bool ok=false;
		for(int j=1;j+k-1<=k+k;j++) 
			if(get_hash==hss[j+k-1]-hss[j-1]*pw[k]) {
				ok=true;
				break;
			}
		if(!ok) return false;
	}
	return true;
}
int32_t main(void) {
    FastIO;
    freopen("STRkARY.INP","r",stdin);
    freopen("STRkARY.OUT","w",stdout);
    cin>>s; n=s.length();
    Cal_Hash();
    for (int i=1;i*i<=n;i++) {
        if (n%i!=0) continue;
        if (kARR(i)) save.push_back(n/i);
        if (n/i==i) continue;
        int j=n/i;
        if (kARR(j)) save.push_back(n/j);
    }
    cout<<save.size()<<endl;
    sort(save.begin(),save.end());
    for (int i=0;i<save.size();i++) cout<<save[i]<<" ";
    return 0;
}