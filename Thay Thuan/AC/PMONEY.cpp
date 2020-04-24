#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int maxn=1e7;
int n=0; vector <char> a, b;
struct data { int id, t; } q[maxn];
vector <int64_t> pre;
int64_t res_mi=0, res_ma=0;
void Enter() {
    freopen("PMONEY.INP","r",stdin);
    freopen("PMONEY.OUT","w",stdout);
    char ch;
    a.push_back(' ');
    while (cin>>ch) {
        n++;
        a.push_back(ch);
    }
    pre.resize(n+2);
    b=a;
}
int32_t main(void) {
    FastIO;
    Enter();
    for (int i=1;i<=n;i++) {
        pre[i]=pre[i-1];
        if (a[i]=='+' || a[i]=='_') pre[i]++;
        else if (a[i]=='-') pre[i]--;
        if (pre[i]<0) {
            cout<<"NIE";
            return 0;
        }
    }
    // for (int i=1;i<=n;i++) cout<<pre[i]<<" "; cout<<endl;
    int64_t cnt=pre[n];
    for (int i=n;i>0;i--) 
    if (a[i]=='_') {
        // cout<<cnt<<" ";
        if (cnt>=2) {
            cnt-=2;
            b[i]='-';
            continue;
        }
        if (cnt==1) {
            cnt--;
            b[i]='0';
            continue;
        }
        b[i]='+';
    }
    // cout<<endl; for (int i=1;i<=n;i++) cout<<b[i]<<" "; cout<<endl;
    cnt=0;
    for (int i=1;i<=n;i++) {
        if (b[i]=='+') cnt++;
        else if (b[i]=='-') cnt--;
        if (cnt<0) {
            cout<<"NIE";
            return 0;
        }
        res_ma+=cnt;
    }
    if (cnt!=0) {
        cout<<"NIE";
        return 0;
    }

    for (int i=1;i<=n;i++) {
        pre[i]=pre[i-1];
        if (a[i]=='-' || a[i]=='_') pre[i]--;
        else if (a[i]=='+') pre[i]++;
    }

    // Solve Min
    b=a; cnt=0;
    int top=0;
    for (int i=1;i<=n;i++) {
        if (a[i]=='_') {
            b[i]='-';
            top++;
            q[top].id=i;
            q[top].t=2;
        }
        while (pre[i]+cnt<0) {
            int x=q[top].id, y=q[top].t;
            top--;
            if (pre[i]+cnt+y>0) {
                top++;
                q[top].id=x;
                q[top].t=1;
                cnt++;
                b[x]='0';
            } else {
                b[x]='+';
                cnt+=y;
            }
        }
    }
    cnt=0;
    for (int i=1;i<=n;i++) {
        if (b[i]=='+') cnt++;
        else if (b[i]=='-') cnt--;
        res_mi+=cnt;
    }
    cout<<res_mi<<" "<<res_ma;
    return 0;
}