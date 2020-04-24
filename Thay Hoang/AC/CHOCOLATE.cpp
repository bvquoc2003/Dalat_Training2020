#include <bits/stdc++.h>

using namespace std;
const string filename = "CHOCOLATE";

#define int long long

struct Line {
	int x1,y1,x2,y2;
	Line(){}
	Line(int _x1,int _y1,int _x2,int _y2) {
		x1 = _x1;
		y1 = _y1;
		x2 = _x2;
		y2 = _y2;
	}
};

vector<Line>L;

typedef pair<int,int> ii;
int w,h,k,x0,y0;
int n;
//int A[1001][1001];
int val_x[300001];
int val_y[300001];
int dir[1001];
int top_x = 0;
int top_y = 0;
map<int,int> vx;
map<int,int> vy;
vector< vector<int> >  A;
vector< vector<bool> > visited;
//bool visited[1001][1001];
vector<int> res;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int bfs(int xs,int ys) {
	queue<ii> CurrList;
	CurrList.push(ii(xs,ys));
	visited[xs][ys] = true;
	int cnt = 0;
	while(!CurrList.empty()) {
		int x = CurrList.front().first;
		int y = CurrList.front().second;     
		cnt += val_x[x]*val_y[y];
		CurrList.pop();
		for (int i=0;i<4;i++)
			if (!(A[x][y] & (1<<i))) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (1 <= xx && xx <= top_x && 1 <= yy && yy <= top_y)
					if (!visited[xx][yy]) {
						visited[xx][yy] = true;
						CurrList.push(ii(xx,yy));
					}
			}
	}
	return cnt;
}

vector<int> coor_x;
vector<int> coor_y;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	freopen("CHOCOLATE.INP","r",stdin);
	freopen("CHOCOLATE.OUT","w",stdout);

	cin >> w >> h >> k >> x0 >> y0;
	dir['U'] = 0;
	dir['R'] = 1;
	dir['D'] = 2;
	dir['L'] = 3;
	string s;
	cin >> s;
	int p_x = x0;
	int p_y = y0;
	int cur_x = x0 + dx[dir[s[0]]];
	int cur_y = y0 + dy[dir[s[0]]];
	int cur_dir = dir[s[0]];
	for (int i=1;i<s.size();i++) {
		if (s[i] != cur_dir) {
			L.push_back(Line(p_x,p_y,cur_x,cur_y));
			p_x = cur_x;
			p_y = cur_y;
			cur_dir = dir[s[i]];
		}
		cur_x += dx[dir[s[i]]];
		cur_y += dy[dir[s[i]]];
		if (i == s.size() - 1)
			L.push_back(Line(p_x,p_y,cur_x,cur_y));
	}
	coor_x.push_back(0);
	coor_y.push_back(0);
	for (int i=0;i<L.size();i++) {
		if (L[i].x1 == L[i].x2 && (L[i].x1 < 0 || L[i].x1 > w)) continue;
		if (L[i].y1 == L[i].y2 && (L[i].y1 < 0 || L[i].y2 > h)) continue;
		L[i].x1 = max(0LL,min(L[i].x1,w));
		L[i].x2 = max(0LL,min(L[i].x2,w));
		L[i].y1 = max(0LL,min(L[i].y1,h));
		L[i].y2 = max(0LL,min(L[i].y2,h));
		coor_x.push_back(L[i].x1);
		coor_x.push_back(L[i].x2);
		coor_y.push_back(L[i].y1);
		coor_y.push_back(L[i].y2);
	}
	coor_x.push_back(w);
	coor_y.push_back(h);

	if (coor_x.size() == 2 && coor_y.size() == 2) {
		cout << w*h;
		return 0;
	}	
	sort(coor_x.begin()+1,coor_x.end());
	int pre_x = 0;
	for (int i=1;i<coor_x.size();i++) {
		if (coor_x[i] != pre_x) {       	
			top_x++;
			val_x[top_x] = (coor_x[i] - coor_x[i-1]);
			pre_x = coor_x[i];
		}			
		vx[coor_x[i]] = top_x;
	}

	sort(coor_y.begin()+1,coor_y.end());
	int pre_y = 0;
	for (int i=1;i<coor_y.size();i++) {
		if (coor_y[i] != pre_y) {       	
			top_y++;
			val_y[top_y] = (coor_y[i] - coor_y[i-1]);
			pre_y = coor_y[i];
		}			
		vy[coor_y[i]] = top_y;
	}

	A.resize(top_x+10);
	visited.resize(top_x+10);
	for (int i=0;i<=top_x+5;i++) {
		A[i].resize(top_y+10);
		visited[i].resize(top_y+10);
		for (int j=0;j<=top_y+5;j++) {
			A[i][j] = 0;
			visited[i][j] = false;
		}	
	}	
	//cerr << top_x << ' ' << top_y << '\n';
	for (int i=0;i<L.size();i++) {
		int a,b,c,d;
		a = L[i].x1;
		b = L[i].y1;
		c = L[i].x2;
		d = L[i].y2;
		if (a == c) {
			if (a > w)
				continue;
			if (a < 0)
				continue;
			if (b > d) swap(b,d);
			a = vx[a]; b = vy[b]; c = vx[c]; d = vy[d];
			//cerr << a << ' ' << b << ' ' << c << ' ' << d << '\n';
			b = max(0LL,min(b,h));
			d = max(0LL,min(d,h));
			for (int i=b+1;i<=d;i++) {
				A[a][i] |= (1<<1);
				A[a+1][i] |= (1<<3);
			}	
		}
		else if (b == d) {
			if (b > h)
				continue;
			if (b < 0)
				continue;	
			if (a > c) swap(a,c);
			a = vx[a]; b = vy[b]; c = vx[c]; d = vy[d];
			//cerr << a << ' ' << b << ' ' << c << ' ' << d << '\n';
			a = max(0LL,min(a,w));
			c = max(0LL,min(c,w));
			for (int i=a+1;i<=c;i++) {
				A[i][b] |= (1<<0);
				A[i][b+1] |= (1<<2);
			}
		}
	}
	//cerr << '!' << '\n';
	for (int i=1;i<=top_x;i++)
		for (int j=1;j<=top_y;j++)
			if (!visited[i][j])
				res.push_back(bfs(i,j));
	sort(res.begin(),res.end());
	cout << res.size() << '\n';
	for (int i=0;i<res.size();i++)
		cout << res[i] << ' ';
}                       	