#include <bits/stdc++.h>

using namespace std;

int t;
long long n;

long long len(long long n) {
    long long l = 1, prek = 0, k = 9, res = 0;
    while (k <= n) {
        res += l * (k - prek);
        prek = k; k = k * 10 + 9; l++;
    }
    return res + (n - prek) * l;
}

int pos(long long n, int pos) {
    stack<int> a;
    while (a.size() > 0) a.pop();

    while (n > 0) {
        a.push(n % 10);
        n /= 10;
    }

    while (pos > 1) {
        a.pop();
        pos--;
    }

    return a.top();
}

int cal(long long n) {
    long long m = len(n);

    int type = 1;
    stack<int> st;

    while (m > 1) {
        if (type == 0) {
            st.push(type);
            m -= (m >> 1);
        } else {
            st.push(type);
            m -= ((m + 1) >> 1);
        }

        type ^= 1;
    }

    while (st.size() > 0) {
        if (st.top() == 1) m <<= 1;
        else m = ((m - 1) << 1) + 1;
        st.pop();
    }

    long long len = 1, prek = 0, k = 9;
    while (m > len * (k - prek)) {
        m -= len * (k - prek);
        prek = k; k = k * 10 + 9; len++;
    }
    prek++;

    long long l = prek, r = k, res;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if ((mid - prek) * len < m) {
            res = mid;
            l = mid + 1;
        } else r = mid - 1;
    }

    return pos(res, m - (res - prek) * len);
}

int main() {
    //freopen("MNUM.INP", "r", stdin);
    //freopen("MNUM.OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;
        cout << cal(n);
    }
}
