#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const int32_t MaxN=100001;
ll n, k, R;
ll a[MaxN], pos[MaxN];
ii b[MaxN];
ll BIT1[MaxN]; // Count number of a[i]>k
ll BIT2[MaxN]; // Cal Prefix Sum
vector <ll> z;

void update_1(ll x) { for(;x>0;x-=x&(-x)) BIT1[x]++; }
ll query_1(ll x) {
    if (x==0) x=1;
    ll ans=0;
    for(;x<=n;x+=x&(-x)) ans+=BIT1[x];
    return ans;
}

void update_2(ll x, ll val) { for(;x<=n;x+=x&(-x)) BIT2[x]+=val; }
ll query_2(ll x) {
    ll ans=0;
    for(;x>0;x-=x&(-x)) ans+=BIT2[x];
    return ans;
}

bool check(ll x) {
    ll pos_l=upper_bound(z.begin(),z.end(),x)-z.begin();
    ll pos_r=upper_bound(z.begin(),z.end(),x)-z.begin();
    pos_r++;
    ll sum=query_2(pos_l)+query_1(pos_r)*x;
    return (sum>=(x*k));
}
ll Answer() {
    ll l=1, r=1e15, ans=0;
    while (l<=r) {
        ll mid=l+(r-l)/2;
        if (check(mid)) {
            ans=mid;
            // cout<<l<<" "<<r<<" "<<mid<<endl;
            l=mid+1;
        } else r=mid-1;
    }
    return ans;
}
int32_t main(void) {
    FastIO;
    freopen("GROUP.IN","r",stdin);
    freopen("GROUP.OUT","w",stdout);
    ll T; cin>>T;
    while (T--) {
        cin>>n>>k>>R; 
        for (ll i=1;i<=n;i++) BIT1[i]=0, BIT2[i]=0;
        for (ll i=1;i<=n;i++) {
            cin>>a[i];
            b[i].first=a[i];
            b[i].second=i;
        }
        sort(b+1,b+1+n); z.clear();
        for (ll i=1;i<=n;i++) {
            pos[b[i].second]=i;
            z.push_back(a[b[i].second]);
        }
        for (ll i=1;i<=R;i++) {
            update_1(pos[i]);
            update_2(pos[i],a[i]);
        }
        for (ll i=R+1;i<=n;i++) {
            update_1(pos[i]);
            update_2(pos[i],a[i]);
            cout<<Answer()<<" ";
        }
        cout<<endl;
    }
    return 0;
}