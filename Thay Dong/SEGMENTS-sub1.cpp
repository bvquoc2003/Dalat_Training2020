#include <bits/stdc++.h>
using namespace std;

const int maxn = 102;

string bit(int a) {
	string res;
	while (a != 0) {
		res = (char)(a % 2 + '0') + res;
		a /= 2;
	}
	while (res.size() < 4) res = "0" + res;

	return res;
}

int w, h;
int a[maxn][maxn];
bool kill[maxn][maxn];
vector<long long> tplt;

void init_a() {
	for (int i = 1; i <= w; i++) {
		a[i][1] |= 8;
		a[i][h] |= 2;
	}
	for (int i = 1; i <= h; i++) {
		a[1][i] |= 1;
		a[w][i] |= 4;
	}
}

void cut(int x1, int y1, int x2, int y2) {
	int x, y;
	if (x1 == x2) {
		if (y1 > y2) swap(y1, y2);
		x = x1;
		if (x < 1 || x >= w) return ;
		for (y = max(y1 + 1, 1); y <= min(y2, h); y++) {
			a[x][y] |= 4;
			a[x+1][y] |= 1;
		}
	}
	else {
		if (x1 > x2) swap(x1, x2);
		y = y1;
		if (y < 1 || y >= h) return ;
		for (x = max(x1+1, 1); x <= min(x2, w); x++) {
			a[x][y] |= 2;
			a[x][y+1] |= 8;
		}
	}
}

long long dt;
void dfs(int x, int y) {
	dt++;
	kill[x][y] = true;

	if (!(a[x][y] & 1) && !(kill[x-1][y])) dfs(x-1, y);
	if (!(a[x][y] & 2) && !(kill[x][y+1])) dfs(x, y+1);
	if (!(a[x][y] & 4) && !(kill[x+1][y])) dfs(x+1, y);
	if (!(a[x][y] & 8) && !(kill[x][y-1])) dfs(x, y-1);
}

int main()
{
	freopen("segments.inp", "r", stdin);
	freopen("segments.out", "w", stdout);

	cin >> w >> h;
	init_a();

	int n;
	cin >> n;
	int x1, y1, x2, y2;
	while (n--) {
		cin >> x1 >> y1 >> x2 >> y2;
		cut(x1, y1, x2, y2);
	}

	for (int i = 1; i <= w; i++)
		for (int j = 1; j <= h; j++)
			if (!kill[i][j]) {
				dt = 0;
				dfs(i, j);
				tplt.push_back(dt);
			}

	sort(tplt.begin(), tplt.end(), greater<int>());

	for (int i = 0; i < tplt.size(); i++) 
		cout << tplt[i] << endl;

	return 0;
}