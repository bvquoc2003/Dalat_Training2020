#include <bits/stdc++.h>
using namespace std;

string rutgon(string s) {
    string res = s;
    int i = 0;
    while (i < (int)res.size()-1) {
        if (abs(res[i] - res[i+1]) == 32) {
            res.erase(res.begin() + i);
            res.erase(res.begin() + i);
            i--;
        }
        else i++;
    }
    return res;
}

string l1, r1, l2, r2;
int f[2003][2003];
void doan_chung(string s1, string s2) {
    if (s1 == s2) return ;
    if (s1.size() == 0) { l2 = s2; return ; }
    if (s2.size() == 0) { l1 = s1; return ; }

    string p = " " + s1, q = " " + s2;
    f[0][0] = 0;
    int mx = 0, rq = 1, rp = 1;

    for (int i = 1; i < (int)p.size(); i++) {
        for (int j = 1; j < (int)q.size(); j++) {
            if (p[i] == q[j])
                f[i][j] = f[i-1][j-1] + 1;
            else f[i][j] = 0;
            if (mx < f[i][j]) {
                mx = f[i][j];
                rp = i; rq = j;
            }
        }
    }

    if (rp-mx > 0) l1 = p.substr(1, rp-mx);
    if (rp != (int)p.size()-1) r1 = p.substr(rp+1, (int)p.size()-1);
    if (rq-mx > 0) l2 = q.substr(1, rq-mx);
    if (rq != (int)q.size()-1) r2 = q.substr(rq+1, (int)q.size()-1);
}

string xau_dao(string s) {
    string res;
    for (int i = 0; i < (int)s.size(); i++) 
        if (s[i] > 90) res = (char)(s[i] - 32) + res;
        else res = (char)(s[i] + 32) + res;
    return res;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    freopen("subword.inp", "r", stdin);
    freopen("subword.out", "w", stdout);

    string x, s;
    cin >> x >> s;
    string res = s;

    x = rutgon(x);
    s = rutgon(s);
    doan_chung(x, s);

    res = l1 + xau_dao(l2) + res + xau_dao(r2) + r1;

    cout << res;

    return 0;
}