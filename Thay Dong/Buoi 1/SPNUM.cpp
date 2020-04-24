#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define int int64_t

template <typename T>
inline void Read(T& x) {
    bool Neg=false;
    char c;
    for (c=getchar();c<'0' || c>'9';c=getchar()) if (c=='-') Neg=!Neg;
    x=c-'0';
    for (c=getchar();c>='0' && c<='9';c=getchar()) x=x*10+c-'0';
    if (Neg) x=-x;
}
template <typename T>
inline void Write(T x) {
    if (x<0) { putchar('-'); x=-x; }
    T p=1;
    for (T temp=x/10;temp>0;temp/=10) p*=10;
    for (;p>0;x%=p,p/=10) putchar(x/p+'0');
}

int sum5[100001];
void InitSum5() {
    for (int i=0;i<=9;i++) sum5[i]=i;
    for (int i=10;i<100001;i++) {
        int x=i, sum=0;
        while (x!=0) {
            sum+=(x%10);
            x/=10;
        }
        sum5[i]=sum;
    }
}
vector <bool> isPrime(160,true);
void Eratosthenes() {
    int N=isPrime.size();
    isPrime[0]=false; isPrime[1]=false;
    for (int i=2;i*i<N;i++) 
    if (isPrime[i]) for (int j=i*i;j<N;j+=i) isPrime[j]=false;
}
vector <int> CP;
void SolveCP() {
    for (int i=1;i<10000001;i++) {
        int sum_digits=0;
        int x=i*i;
        while (x!=0) {
            sum_digits+=sum5[x%100000];
            x/=100000;
        }
        if (isPrime[sum_digits]) CP.push_back(i*i);
    }
    // sort(CP.begin(),CP.end());
}
vector <vector<int> > f;
int Solve(int pos, int sum) {
    if (f[pos][sum]!=-1) return f[pos][sum];
    if (pos>15) {
        f[pos][sum]=isPrime[sum];
        return isPrime[sum];
    }
    int tmp=0LL;
    for (int c=0;c<10;c++) tmp+=Solve(pos+1,sum+c);
    return f[pos][sum]=tmp;
}
int Int(char ch) {return int(ch-'0');}
int cnt;
int Calc(int pos, int sum, string s) {
    if (pos>15) return isPrime[sum];
    int tmp=0LL;
    for (int c=0;c<Int(s[pos]);c++) tmp+=f[pos+1][sum+c];
    tmp+=Calc(pos+1,sum+Int(s[pos]),s);
    return tmp;
}
string s_a,s_b;
int a, b, res;
string to_str(int x) {
    string s="";
    while (x!=0) {
        s=char((x%10)+48)+s;
        x/=10;
    }
    while (s.length()<16) s="0"+s;
    return s;
}
int32_t main(void) {
    FastIO;
    freopen("SPNUM.INP","r",stdin);
    freopen("SPNUM.OUT","w",stdout);
    InitSum5();
    Eratosthenes();
    SolveCP();
    f.resize(20,vector<int> (160,-1LL));
    Solve(1,0);
    int T; Read(T);
    while (T--) {
        Read(a); Read(b);
        s_a=to_str(a-1);
        s_b=to_str(b);
        res=Calc(1,0,s_b)-Calc(1,0,s_a);
        int pos_l, pos_r; vector <int>::iterator it;
        it=lower_bound(CP.begin(),CP.end(),a);
        pos_l=it-CP.begin();
        it=upper_bound(CP.begin(),CP.end(),b);
        pos_r=--it-CP.begin();
        if (pos_l<=pos_r) res-=(pos_r-pos_l+1);
        Write(res); putchar('\n');
    }
    return 0;
}