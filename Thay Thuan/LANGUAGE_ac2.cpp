#include <bits/stdc++.h>

using namespace std;

#define int long long

map<string,bool> lul;

typedef pair<int,int> ii;

struct Node
{
	int nxt[2];
	int suf;
	Node()
	{
		nxt[0] = nxt[1] = -1;
		suf = 0;
	}
};

vector<int> AdjList[1000001];
int cnt_ed[1000001];
vector<Node> Trie;
int d;
int m,n;
vector<string> a;
int res = 0;

void update(const string &s)
{
	int cur = 0;
	for (int i=0;i<s.size();i++)
	{
		if (Trie[cur].nxt[s[i] - '0'] == -1)
		{
			Trie.push_back(Node());
			Trie[cur].nxt[s[i] - '0'] = Trie.size() - 1;
		}
		cur = Trie[cur].nxt[s[i] - '0'];
	}
	cnt_ed[cur]++;
}

void build_suf()
{
	queue<int> CurrList;
	for (int i=0;i<2;i++)
	{
		if (Trie[0].nxt[i] != -1)
		{
			CurrList.push(Trie[0].nxt[i]);
			Trie[Trie[0].nxt[i]].suf = 0;
			AdjList[0].push_back(Trie[0].nxt[i]);
			AdjList[Trie[0].nxt[i]].push_back(0);
		}
		else
			Trie[0].nxt[i] = 0;
	}
	while(!CurrList.empty())
	{
		int u = CurrList.front();
		CurrList.pop();
		for (int i=0;i<2;i++)
			if (Trie[u].nxt[i] != -1)
			{
				int z = u;
				int v = Trie[u].nxt[i];
				u = Trie[u].suf;
				while(Trie[u].nxt[i] == -1)
					u = Trie[u].suf;
				Trie[v].suf = Trie[u].nxt[i];
				AdjList[Trie[u].nxt[i]].push_back(v);
				AdjList[v].push_back(Trie[u].nxt[i]);
				CurrList.push(v);
				u = z;										
			}
	}
}

void build_cnt()
{
	queue<ii> CurrList;
	CurrList.push(ii(0,-1));
	while(!CurrList.empty())
	{
		int u = CurrList.front().first;
		int p = CurrList.front().second;
		CurrList.pop();
		//cerr << '!' << u << ' ' << cnt_ed[u] << '\n';
    	for (int i=0;i<AdjList[u].size();i++)
    	{
			int v = AdjList[u][i];
			if (v != p)
			{
				cnt_ed[v] += cnt_ed[u];
				CurrList.push(ii(v,u));
			}			    		
    	}
	}
}

int nxt_state(int u,int z)
{
	//cerr << '!' << u << ' ' << Trie[u].nxt[z] << '\n';
	if (Trie[u].nxt[z] != -1)
		return Trie[u].nxt[z];
	return nxt_state(Trie[u].suf,z);	
}

void query(const string &T)
{
	//cerr << T << '\n';
	int cur = 0;
	for (int i=0;i<T.size();i++)
	{		
		cur = nxt_state(cur,T[i] - '0');
		//cerr << '!' << cur << '\n';
		res += cnt_ed[cur];
	}
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n;
	a.resize(m);
	for (int i=0;i<m;i++)
	{
		a[i].resize(n);
		for (int j=0;j<n;j++)
			cin >> a[i][j];
	}
	Trie.push_back(Node());
	cin >> d;
	while(d--)
	{
		string s;
		cin >> s;
		if (lul[s])
			continue;
		lul[s] = true;	
		update(s);
	}
	build_suf();
	build_cnt();
	//for (int i=0;i<=8;i++)
	//	cerr << Trie[i].suf << ' ';
	for (int i=0;i<m;i++)
	{
		query(a[i]);
		//cerr << "CUR_RES: " << res << '\n';
	}	
	cout << res;
}