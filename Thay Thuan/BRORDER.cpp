#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int res;
bool check(string str) {
    stack <char> a;
	for(int i=0;i<str.length();i++) {
		if (str[i]=='(') a.push(str[i]);
		else {
			if(!a.empty()) {
				if(str[i]==')' && a.top()!='(') return false;
				a.pop();
			} else return false;
		}
	}
	return a.empty();
}
int n; string s;
int32_t main(void) {
    FastIO;
    freopen("BRORDER.INP","r",stdin);
    freopen("BRORDER.OUT","w",stdout);
    int T; cin>>T;
    while (T--) {
        res=0;
        cin>>s; n=s.length();
        do if (check(s)) res++; 
        while (next_permutation(s.begin(),s.end(),greater<char>()));
        cout<<res<<endl;
    }
    return 0;
}