#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define X1 first
#define X2 second
using namespace std;
typedef pair <int,int> ii;
int n, h;
vector <ii> a;
int res=INT_MIN;
int32_t main(void) {
    FastIO;
    freopen("GLIDER.INP","r",stdin);
    freopen("GLIDER.OUT","w",stdout);
    cin>>n>>h; a.resize(n+1);
    for (int i=1;i<=n;i++) {
        cin>>a[i].X1>>a[i].X2;
        if (a[i].X1>a[i].X2) swap(a[i].X1,a[i].X2);
    }
    if (n<=1000) { //Sub nho
        for (int i=1;i<=n;i++) {
            int t=(a[i].X2-a[i].X1);
            int k=h;
            for (int j=i+1;j<=n;j++) {
                int x=a[j].X1-a[j-1].X2;
                k-=x; t+=x;
                if (k<=0) {
                    t-=abs(k);
                    break;
                }
                t+=a[j].X2-a[j].X1;
            }
            if (k>0) t+=k;
            res=max(res,t);
        }
        cout<<res;
        return 0;
    }
    //AC
    vector <int> b(n+1), c(n+1);
    for (int i=1;i<=n;i++) {
        b[i]=b[i-1]+a[i].X2-a[i].X1; //Cong don tong cac vung khi nong
        c[i]=c[i-1]+abs(a[i].X1-a[i-1].X2); //cong don khoang cach giua cac vung khi nong
    }
    for (int i=1;i<=n;i++) {
        int x=lower_bound(c.begin()+2,c.end(),h+c[i])-c.begin()-1; //tim kiem nhi phan 
        res=max(res,b[x]-b[i-1]+h);
    }
    cout<<res;
    return 0;
}