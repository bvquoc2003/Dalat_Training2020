#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;

const int N = 102;

struct line { int x1, y1, x2, y2; };

int w, h;
int a[N][N];
bool mark[N][N];
vector<int64_t> tplt;

int n = 0, m = 0;
vector<int> cx, cy;
int kc_x[N], kc_y[N];
line l[N];
int ln = 0;

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

int search_vt(vector<int> v, int x) {
	return lower_bound(v.begin(), v.end(), x) - v.begin();
}

void remake_l() {
	for (int i = 1; i <= ln; i++) {
		l[i].x1 = search_vt(cx, l[i].x1);
		l[i].y1 = search_vt(cy, l[i].y1);
		l[i].x2 = search_vt(cx, l[i].x2);
		l[i].y2 = search_vt(cy, l[i].y2);
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

void push_c(int x, int y) {
	if (x > 0 && x <= w && x != cx[search_vt(cx, x)]) cx.push_back(x);
	if (y > 0 && y <= h && y != cy[search_vt(cy, y)]) cy.push_back(y);
	sort(cx.begin(), cx.end());
	sort(cy.begin(), cy.end());
}

void push_l(int i, int x1, int y1, int x2, int y2) {
	l[i].x1 = x1;
	l[i].y1 = y1;
	l[i].x2 = x2;
	l[i].y2 = y2;
}

int64_t dt;
void dfs(int x, int y) {
	dt += (int64_t)(kc_x[x] * kc_y[y]);
	mark[x][y] = true;

	if (!(a[x][y] & 1) && !(mark[x-1][y])) dfs(x-1, y);
	if (!(a[x][y] & 2) && !(mark[x][y+1])) dfs(x, y+1);
	if (!(a[x][y] & 4) && !(mark[x+1][y])) dfs(x+1, y);
	if (!(a[x][y] & 8) && !(mark[x][y-1])) dfs(x, y-1);
}

int32_t main() {
	FastIO;
	freopen("segments.inp", "r", stdin);
	freopen("segments.out", "w", stdout);

	cin >> w >> h;

	cx.push_back(0), cy.push_back(0);
	push_c(w, h);

	cin >> ln;
	int x1, y1, x2, y2;
	for (int i = 1; i <= ln; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		push_c(x1, y1);
		push_c(x2, y2);
		push_l(i, x1, y1, x2, y2);
	}

	w = (int)cx.size() - 1;
	h = (int)cy.size() - 1;

	for (int i = 1; i <= w; i++) kc_x[i] = cx[i] - cx[i-1];
	for (int i = 1; i <= h; i++) kc_y[i] = cy[i] - cy[i-1];

	init_a();
	remake_l();

	for (int i = 1; i <= ln; i++) 
		cut(l[i].x1, l[i].y1, l[i].x2, l[i].y2);

	for (int i = 1; i <= w; i++)
		for (int j = 1; j <= h; j++)
			if (!mark[i][j]) {
				dt = 0;
				dfs(i, j);
				tplt.push_back(dt);
			}

	sort(tplt.begin(), tplt.end(), greater<int>());

	for (int i = 0; i < tplt.size(); i++) 
		cout << tplt[i] << endl;

	return 0;
}