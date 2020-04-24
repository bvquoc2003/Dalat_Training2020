#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007
using namespace std;
int n, m;
int64_t res=0;
vector <int> a;
int32_t main(void) {
    FastIO;
    freopen("triple.inp","r",stdin);
    freopen("triple.out","w",stdout);
    cin>>n>>m; a.resize(n+1);
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a.begin()+1,a.end());
    for(int mid=2;mid<n;mid++) {
        int l=1, r=n;
        while(l<mid && mid<r){
            if(a[l]+a[mid]+a[r]==m){
                l++;
                r--;
                int l_tmp=1, r_tmp=1;
                while(a[l]==a[l-1] && l<mid) {
                    l++;
                    l_tmp++;
                }
                while(a[r]==a[r+1] && mid<r) {
                    r--;
                    r_tmp++;
                }
                res+=(l_tmp*r_tmp);
                res%=MOD;
                continue;
            }
            if(a[l]+a[mid]+a[r]<m) {
                l++;
                continue;
            }
            if(a[l]+a[mid]+a[r]>m) r--;
        }
    }
    cout<<res;
    return 0;
}