#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define int long long
const int N=2003;
int n, c[N], f[N][N], r[N][N];
int psum[N];
int freq(int i, int j) {return psum[j]-psum[i-1];}
void Enter() {
    freopen("OPTBST.INP","r",stdin);
    cin>>n; psum[0]=0;
    for (int i=1;i<=n;i++) {
        cin>>c[i];
        f[i][i]=c[i];
        psum[i]=psum[i-1]+c[i];
    }
}
int res;
void DP() {
    for (int t=1;t<=n;t++) 
    for (int i=1;i<=n-t;i++) {
        int j=i+t;
        int tmp=LLONG_MAX, k0=-1;
        if (r[i][j-1]==0 || r[i+1][j]==0) {
            r[i][j-1]=i;
            r[i+1][j]=j;
        }
        for (int k=r[i][j-1];k<=r[i+1][j];k++) 
        if (freq(i,j)+f[i][k-1]+f[k+1][j]<tmp) {
            tmp=freq(i,j)+f[i][k-1]+f[k+1][j];
            k0=k;
        }
        f[i][j]=tmp;
        r[i][j]=k0;
    }
    res=f[1][n];
}
void Print() {
    freopen("OPTBST.OUT","w",stdout);
    cout<<res;
}
int32_t main(void) {
    FastIO;
    Enter();
    DP();
    Print();
    return 0;
}

/*
freq[i][j]=c[i]+c[i+1]+...+c[j]
Gọi f[i][j]: số phép so sánh ít nhất trên BST ứng với các khóa từ [i,j]
Gọi r[i][j]: gốc cây đó
NX: r[i][j-1]<=r[i][j]<=r[i+1][j]
- Nếu gốc chứa khóa k (k thuộc {i..j})
    f[i][j]=min{freq[i,j]+f[i][k-1]+j[k+1][j]};
*/
//Knuth Optimifation
/*
Setup
f[i][i]=c[i];

void DP() {
    for (int t=1;t<=n;t++) 
    for (int i=1;i<=n-t;i++) {
        int j=i+t;
        for (int k=i;k<=j;k++) {
            f[i][j]=MIN(freq[i][j]+f[i][k-1]+f[k+1][j]);
            r[i][j]= giá trị k để f[i][j] đạt MIN
        }
    }
}
//Optimize
void DP() {
    for (int t=1;t<=n;t++) 
    for (int i=1;i<=n-t;i++) {
        int j=i+t;
        for (int k=r[i][j-1];k<=r[i+1][j];k++) f[i][j]=MIN(freq[i][j]+f[i][k-1]+f[k+1][j]);
    }
}

res=f[1][n];
*/