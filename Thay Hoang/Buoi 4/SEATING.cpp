#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N=100001;
#define int long long
typedef pair<int,int> ii;
struct Query {
	int l, r, id;
	Query(){}
} Q[N];
bool operator < (const Query &a, const Query &b) { return a.l<b.l; }
struct cmp {
	bool operator() (const ii &a, const ii &b)
	const {
		if (a.first != b.first) return a.first>b.first;
		return a.second<b.second;	
	}
};

int k,n, res[N];
set<int> vt; //vi tri ghe da duoc su dung
set<ii, cmp> Set; // ii(l,i) vi tri bat dau khoang la i, do dai l

int32_t main(void) {
	FastIO;
    freopen("SEATING.INP","r",stdin);
    freopen("SEATING.OUT","w",stdout);
	cin>>k>>n;
	for (int i=1;i<=n;i++) {
		cin>>Q[i].l>>Q[i].r;
		Q[i].id=i;
	}
	sort(Q+1,Q+1+n);
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	Set.insert(ii(k,1));
	for (int i=1;i<=n;i++) {
		while(!pq.empty() && pq.top().first <= Q[i].l) {
			int l,r;
			set<int>::iterator it=vt.upper_bound(pq.top().second);
			if (it==vt.end()) r=k+1;
			else r=*it;
			Set.erase(ii(r-pq.top().second-1,pq.top().second+1));
			it=vt.lower_bound(pq.top().second);
			if (it==vt.begin()) l=0;
			else {
				it--;
				l = *it;
			}
			Set.erase(ii(pq.top().second-l-1,l+1));
			vt.erase(pq.top().second);
			Set.insert(ii(r-l-1,l+1));	
			pq.pop();
		}
		ii tmp=(*Set.begin());
		Set.erase(Set.begin());
		int pos=tmp.second+(tmp.first-1)/2;
		Set.insert(ii(pos-tmp.second,tmp.second));
		Set.insert(ii((tmp.second+tmp.first-pos-1),pos+1));
		vt.insert(pos);
		res[Q[i].id]=pos;
		pq.push(ii(Q[i].r,pos));
	}
	for (int i=1;i<=n;i++) cout<<res[i]<<' ';
}
/*
L[i]= người ngồi bên TRÁI người i
R[i]= người ngồi bên PHẢI người i

link(x,y) { // đặt 2 người x,y cạnh nhau (ko có ai ngồi giữa)
    R[x]=y;
    L[y]=x;
}

Thêm người c vào giữa a&b
biết vị trí người c=(pos(a)+pos(b))/2=pos(c);
link(a,c); link(c,b);

Quản lí khoảng trống:
- Luu 2 người ngồi 2 đầu
- Lấy ra khoảng trống max
--> priority_queue
*/