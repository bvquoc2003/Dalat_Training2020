#include <bits/stdc++.h>

using namespace std;

#define For(i, a, b) for(int64_t i = a; i <= b; i++)
#define Fod(i, a, b) for(int64_t i = a; i >= b; i--)

string st = "";

int64_t leng(int64_t n)
{
	if (n < 10) return n;
	int64_t d = 10, m = 0, i = 1;
	do
		m += (d - d / 10) * i,
		d *= 10,
		i++;
	while (d <= n);
	d /= 10;
	m += (n - d + 1) * i;
	return m;
}

int64_t cnt(int64_t m)
{
	int64_t u = m, d = 0;
	while (u > 1) {
        d++;
        if (d % 2 == 0) u = u/2 + u%2;
        else u /= 2;
	}
	return d;
}

int64_t idx(int64_t d)
{
	int64_t k = 1;
	Fod(i, d, 1)
        if (i % 2 == 0)
            (k *= 2) -= 1;
        else
            k *= 2;
	return k;
}

int64_t digit(int64_t nx, int64_t d)
{
	int64_t tmp = nx;
	For(i, 1, d)
	tmp /= 10;
	return tmp % 10;
}

int64_t num(int64_t k)
{
	int64_t d = 1, m = 0, i = 0, nx = 0, j = 0;
	do
	{
		d *= 10,
		++i,
		m += (d - d/10) * i;
	}
	while (m <= k);

	m -= (d - d/10) * i;
	d /= 10;
	nx = d + (k - m - 1) / i;
	j = (k - m - 1) % i + 1;
	return digit(nx, i-j);
}

int main()
{
//	freopen("in.txt", "r", stdin);
	int64_t k;
	cin >> k;
	For(j, 1, k)
	{
		int64_t n, m, d, k, x;
		cin >> n;
		m = leng(n);
		d = cnt(m);
		k = idx(d),
		x = num(k);
		cout << x;
	}
}
