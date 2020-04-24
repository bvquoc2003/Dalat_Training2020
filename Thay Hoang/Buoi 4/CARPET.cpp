#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
template <typename T>
inline void Read(T& x) {
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}

template <typename T>
inline void Write(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}

const int N=2003;
struct query {char ch; int a, b, c, d;} q[N];
int m, n, k, a[N][N];
void ReverseV(int x1, int y1, int x2, int y2) {
    int x_t=x2, x_m=x1+((x2-x1)>>1);
    for (int x=x1;x<=x_m;x++) {
        for (int y=y1;y<=y2;y++) swap(a[x][y],a[x_t][y]);
        x_t--;
    }
}
void ReverseH(int x1, int y1, int x2, int y2) {
    int y_m=y1+((y2-y1)>>1);
    for (int x=x1;x<=x2;x++) {
        int y_t=y2;
        for (int y=y1;y<=y_m;y++) {
            swap(a[x][y],a[x][y_t]);
            y_t--;
        }
    }
}
int32_t main(void) {
    FastIO;
    freopen("CARPET.INP","r",stdin);
    freopen("CARPET.OUT","w",stdout);
    Read(m); Read(n); Read(k);
    for (int i=1;i<=m;i++) for (int j=1;j<=n;j++) a[i][j]=(i-1)*n+j;
    for (int i=1;i<=k;i++) {
        scanf("%c",&q[i].ch);
        Read(q[i].a); Read(q[i].b); Read(q[i].c); Read(q[i].d);
    }
    reverse(q+1,q+1+k); 
    for (int i=1;i<=k;i++)
    if (q[i].ch=='H') ReverseH(q[i].a,q[i].b,q[i].c,q[i].d);
    else ReverseV(q[i].a,q[i].b,q[i].c,q[i].d);
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            Write(a[i][j]);
            putchar(' ');
        }
        putchar('\n');
    }
    return 0;
}