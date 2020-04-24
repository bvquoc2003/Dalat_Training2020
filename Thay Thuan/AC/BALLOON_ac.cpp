#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
const int BIG = 1e9 + 555;
const int maxN = 200 + 5;

ll memo[5][maxN][maxN][maxN];
int n, id[300];
bool calc[5][maxN][maxN][maxN];
string s;

void init(){
	for(int curColor = 1; curColor <= 4; curColor++){
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= n; j++){
				for(int k = 0; k <= n; k++){
					calc[curColor][i][j][k] = false;
				}
			}
		}
	}
}

ll dp(int curColor, int sz, int lf, int rt){
	//cerr << lf << ' ' << rt << '\n';
	if(lf > rt){
		//cerr << curColor << ' ' << sz << ' ' << lf << ' ' << rt << '\n';
		if(sz >= 2){
			return sz * sz;
		}
		return -INF;
	}

	if(calc[curColor][sz][lf][rt]){
		return memo[curColor][sz][lf][rt];
	}
	
	ll ans = -INF;
	if(id[s[lf]] == curColor){
		//cerr << "x " << lf << ' ' << rt << '\n';
		ans = max(ans, dp(curColor, sz + 1, lf + 1, rt));
	} else {
		//cerr << "y " << lf << ' ' << rt << '\n';
		if(sz >= 2){
			ans = max(ans, dp(id[s[lf]], 0, lf, rt) + sz * sz);
		}

		for(int k = lf + 1; k <= rt; k++){
			if(id[s[k]] == curColor){
				//cerr << "from " << lf << ", " << rt << " to " << k << ", " << rt << '\n';
				ans = max(ans, dp(curColor, sz, k, rt) + dp(id[s[lf]], 0, lf, k - 1));
			}
		}
	}

	calc[curColor][sz][lf][rt] = true;
	return (memo[curColor][sz][lf][rt] = ans);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int nTest;	cin >> nTest;
	id['R'] = 1;
	id['G'] = 2;
	id['B'] = 3;
	id['Y'] = 4;

	while(nTest--){
		cin >> s;
		n = (int)s.size();
	
		init();
		cout << max(0LL, dp(id[s[0]], 0, 0, n - 1)) << '\n';
	}

	return 0;
}