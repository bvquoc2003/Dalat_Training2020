#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
const int BIG = 1e9 + 555;

ll f(ll x, bool tp){
	if(x == 1){
		return 1;
	}
	if(!tp){
		return 2 * f(x / 2, !tp);
	}

	return 2 * f(x - (x / 2), !tp) - 1;
}

string toNum(ll x){
	string res = "";
	//cerr << "toNum " << x << '\n';
	while(x){
		res.push_back((char)((x % 10) + '0'));
		x /= 10;
	}
	reverse(res.begin(), res.end());
	return res;
}

char g(ll n){
	string s = "";
	for(int i = 1; i <= n; i++){
		s += toNum(i);
	}

	//cerr << f((int)s.size(), 0) << '\n';
	int id = f((int)s.size(), 0);
	return s[id - 1];
}

ll pw[20];

ll digitCnt(ll n){
	int cnt = 0;
	while(n){
		n /= 10;
		cnt++;
	}
	return cnt;
}

char getNum(ll x){
	int grp = -1;
	ll s = 0, e = 0, rem = x;
	for(int i = 1; i <= 17; i++){
		s = e + 1;
		e = s + i * (pw[i] - 1 - pw[i - 1] + 1) - 1;
		if(s <= x && x <= e){
			grp = i;
			rem = (x - s + 1);
		}
	}
	
	//cerr << "grp = " << grp << '\n';
	//cerr << "rem = " << rem << '\n';

	ll cnt = (pw[grp] - 1 - pw[grp - 1] + 1);
	s = pw[grp - 1];
	e = pw[grp] - 1;
	
	if(rem <= s + grp - 1){
		string ss = toNum(s);
		return ss[rem - 1];
	}
	
	//cerr << "lululululu\n";
	ll lo = s, hi = e, id = s;
	//cerr << s << '\n';
	//cerr << e << '\n';

	while(lo <= hi){
		ll mid = (lo + hi) / 2;
		//cerr << mid << '\n';
		if(grp * (mid - s + 1) < rem){
			lo = mid + 1;
			id = mid;
		} else {
			hi = mid - 1;
		}
	}
	
	//cerr << "id = " << id << '\n';
	//cerr << "id + 1 = " << id + 1 << '\n';

	rem -= grp * (id - s + 1);
	
	//cerr << rem << '\n';

	string ss = toNum(id + 1);
	//cerr << ss << '\n';
	return ss[rem - 1];
}

char G(ll n){
	ll d = digitCnt(n);
	ll cnt = 0;

	for(int i = 1; i < d; i++){
		cnt += i * 9 * pw[i - 1];
	}

	cnt += d * (n - pw[d - 1] + 1);

	ll pos = f(cnt, 0);
	
	//cerr << "pos = " << pos << '\n';

	return getNum(pos);
}

const int maxN = 1e5 + 55;
ll a[maxN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
		
	pw[0] = 1;
	for(int i = 1; i < 19; i++){
		pw[i] = (pw[i - 1] * 10);
	}
	
	int k;	cin >> k;

	for(int i = 1; i <= k; i++){
		cin >> a[i];
	}

	for(int i = 1; i <= k; i++){
		//cerr << g(a[i]) << ' ';
		cout << G(a[i]);
		//cerr << '\n';
	}
	cout << '\n';

	return 0;
}