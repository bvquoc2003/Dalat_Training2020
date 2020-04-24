#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int w, h;
vector <vector<int>> a;
vector <vector<bool>> mark;

void Cut(int x1, int y1, int x2, int y2) {
	int x, y;
	if (x1==x2) {
		if (y1>y2) swap(y1,y2);
		x=x1;
		if (x<1 || x>=w) return;
		for (y=max(y1+1,1);y<=min(y2,h);y++) {
			a[x][y] |= 4;
			a[x+1][y] |= 1;
		}
	}
	else {
		if (x1>x2) swap(x1,x2);
		y=y1;
		if (y<1 || y>=h) return ;
		for (x=max(x1+1,1);x<=min(x2,w);x++) {
			a[x][y] |= 2;
			a[x][y+1] |= 8;
		}
	}
}
void Enter() {
	freopen("chocolate.inp","r",stdin);
	cin>>w>>h;
	a.resize(w+1,vector<int>(h+1));
	mark.resize(w+1,vector<bool>(h+1));
	for (int i=1;i<=w;i++) {
		a[i][1] |= 8;
		a[i][h] |= 2;
	}
	for (int i=1;i<=h;i++) {
		a[1][i] |= 1;
		a[w][i] |= 4;
	}
	int k, x1, y1, x2, y2;
	cin>>k>>x1>>y1;
	while (k--) {
		x2=x1; y2=y1;
		char ch; cin>>ch;
		if (ch=='R') x2++;
		else if (ch=='D') y2--;
		else if (ch=='U') y2++;
		else x2--;
		Cut(x1,y1,x2,y2);
		x1=x2; y1=y2;
	}
}

int64_t res;
void dfs(int x, int y) {
	res++;
	mark[x][y]=true;
	if (!(a[x][y] & 1) && !(mark[x-1][y])) dfs(x-1, y);
	if (!(a[x][y] & 2) && !(mark[x][y+1])) dfs(x, y+1);
	if (!(a[x][y] & 4) && !(mark[x+1][y])) dfs(x+1, y);
	if (!(a[x][y] & 8) && !(mark[x][y-1])) dfs(x, y-1);
}

vector<int64_t> tplt;
void Print() {
	freopen("chocolate.out","w",stdout);
	sort(tplt.begin(),tplt.end());
	cout<<tplt.size()<<endl;
	for (int64_t x:tplt) cout<<x<<" ";
}
int32_t main(void) {
	FastIO;
	Enter();
	for (int i=1;i<=w;i++)
		for (int j=1;j<=h;j++)
			if (!mark[i][j]) {
				res=0;
				dfs(i,j);
				tplt.push_back(res);
			}
	Print();
	return 0;
}