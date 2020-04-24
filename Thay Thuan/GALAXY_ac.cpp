#include <bits/stdc++.h>

using namespace std;

// Boruvka algorithm + Segment tree
// Thanks _Kuroni-senpai_ UWU

typedef long long ll;
typedef pair<int,int> ii;

struct Node
{
	ii f[2]; // Index and the CC that it is in
	Node(){}
}Tree_2[400001];

map<ii,bool> hav[100001];
int n,m;
int p[100001];
int col[100001];
int top = 0;
vector<ii> Q[100001];
vector<int> AdjList[100001];
vector<ii> upd;
bool visited[100001];
ii Tree[400001];

ll res = 0;

void update(int node,int l,int r,int pos,int val)
{
	if (l == r)
	{
		Tree[node] = ii(pos,val);
		return;
	}
	int mi = (l+r)/2;
	if (pos <= mi)
		update(node*2,l,mi,pos,val);	
	else	
		update(node*2+1,mi+1,r,pos,val);
	if (Tree[node*2].second < Tree[node*2+1].second)
		Tree[node] = Tree[node*2];
	else
		Tree[node] = Tree[node*2+1];	
}

ii query(int node,int l,int r,int ll,int rr)
{
	if (r < ll || rr < l)
		return ii(-1,1e9);
	if (ll <= l && r <= rr)
		return Tree[node];
	int mi = (l+r)/2;
	ii a = query(node*2,l,mi,ll,rr);
	ii b = query(node*2+1,mi+1,r,ll,rr);
	if (a.second < b.second)
		return a;
	return b;			
}

void update_2(int node,int l,int r,int val,int ll,int rr)
{
	if (r < ll || rr < l)
		return;
	if (ll <= l && r <= rr)
	{
		if (Tree_2[node].f[0] == ii(-1,-1))
		{
			Tree_2[node].f[0] = ii(val,col[val]);
			return;
		}
		else if (Tree_2[node].f[0].second != col[val])
		{
			if (p[Tree_2[node].f[0].first] > p[val])
			{
				Tree_2[node].f[1] = Tree_2[node].f[0];
				Tree_2[node].f[0] = ii(val,col[val]);
			}
			else if (Tree_2[node].f[1] == ii(-1,-1))
				Tree_2[node].f[1] = ii(val,col[val]);
			else if (p[Tree_2[node].f[1].first] > p[val])
				Tree_2[node].f[1] = ii(val,col[val]);	
		}	
		else if (p[Tree_2[node].f[0].first] > p[val])
			Tree_2[node].f[0] = ii(val,col[val]);
		return;
	}
	int mi = (l+r)/2;
	update_2(node*2,l,mi,val,ll,rr);
	update_2(node*2+1,mi+1,r,val,ll,rr);	
}

ii query_2(int node,int l,int r,int x)
{ 
	if (l == r)
	{
		if (Tree_2[node].f[0] != ii(-1,-1))
		{
			if (Tree_2[node].f[0].second == col[x])
			{
				if (Tree_2[node].f[1] != ii(-1,-1))
					return ii(Tree_2[node].f[1].first,p[Tree_2[node].f[1].first]);
				else
					return ii(-1,1e9);
			}
			else
				return ii(Tree_2[node].f[0].first,p[Tree_2[node].f[0].first]);
		}
		else
			return ii(-1,1e9);
	}
	int mi = (l+r)/2;
	ii a;
	if (x <= mi)
		a = query_2(node*2,l,mi,x);
	else
		a = query_2(node*2+1,mi+1,r,x);	
	if (Tree_2[node].f[0] != ii (-1,-1))
	{
		if (Tree_2[node].f[0].second == col[x])
		{
			if (Tree_2[node].f[1] != ii(-1,-1))
			{
				ii b = ii(Tree_2[node].f[1].first,p[Tree_2[node].f[1].first]);
				if (a.second < b.second)
					return a;
				return b;
			}
			else
				return a;
		}
		else
		{
			ii b = ii(Tree_2[node].f[0].first,p[Tree_2[node].f[0].first]);
			if (a.second < b.second)
				return a;
			return b;	
		}
	}
	else
		return a;
}

void dfs(int s,int cur_col)
{
	visited[s] = true;
	col[s] = cur_col;
	for (int i=0;i<AdjList[s].size();i++)
	{
		int v = AdjList[s][i];
		if (!visited[v])
			dfs(v,cur_col);
	}
}

void bfs(int s)
{
	vector<int> z;
	queue<int> CurrList;
	CurrList.push(s);
	z.push_back(s);
	visited[s] = true;
	while(!CurrList.empty())
	{
		int u = CurrList.front();
		update(1,1,n,u,1e9);
		CurrList.pop();
		for (int i=0;i<AdjList[u].size();i++)
		{
			int v = AdjList[u][i];
			if (!visited[v])
			{
				visited[v] = true;
				CurrList.push(v);
				z.push_back(v);
			}
		}		
	}
	ii tot_mn = ii(-1,1e9);
	int id = -1;
	for (int i=0;i<z.size();i++)
	{
		ii mn = ii(-1,1e9);
		for (int j=0;j<Q[z[i]].size();j++)
		{
			int a = Q[z[i]][j].first;
			int b = Q[z[i]][j].second;
			ii cur = query(1,1,n,a,b);
			if (mn.second > cur.second)
				mn = cur;
		}
		if (id == -1)
		{
			if (mn.first != -1)
			{
				id = z[i];
				tot_mn = mn;
			}	
		}
		else if (tot_mn.second + p[id] > mn.second + p[z[i]])
		{
			id = z[i];
			tot_mn = mn;
		}	
	}

	// Case 2 y E [a,b] -> x
	for (int i=0;i<z.size();i++)
	{
		ii mn = query_2(1,1,n,z[i]);
		if (id == -1)
		{
			if (mn.first != -1)
			{
				id = z[i];
				tot_mn = mn;
			}	
		}
		else if (tot_mn.second + p[id] > mn.second + p[z[i]])
		{
			id = z[i];
			tot_mn = mn;
		}
	}
	if (id != -1)	
		upd.push_back(ii(id,tot_mn.first));
	for (int i=0;i<z.size();i++)
		update(1,1,n,z[i],p[z[i]]);
}

void cal_res(int u)
{
	visited[u] = true;
	for (int i=0;i<AdjList[u].size();i++)
	{
		int v = AdjList[u][i];
		if (!visited[v])
		{
			res += p[u] + p[v];
			cal_res(v);
		}
	}
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i=1;i<=4*n;i++)
	{
		Tree_2[i].f[0] = Tree_2[i].f[1] = ii(-1,-1);
		Tree[i] = ii(-1,1e9);
	}	
	for (int i=1;i<=n;i++)
	{
		cin >> p[i];
		update(1,1,n,i,p[i]);
		col[i] = i;
	}	
	for (int i=1;i<=m;i++)
	{
		int x,a,b;
		cin >> x >> a >> b;
		Q[x].push_back(ii(a,b));
		update_2(1,1,n,x,a,b);
	}
	while(1)
	{
		top = 0;
		upd.clear();
		int cnt = 0;
		for (int i=1;i<=n;i++)
			visited[i] = false;	    	
		for (int i=1;i<=n;i++)
			if (!visited[i])
			{
				cnt++;
				dfs(i,++top);				
			}
		if (cnt == 1)
			break;
		for (int i=1;i<=n;i++)
			visited[i] = false;
		for (int i=1;i<=n;i++)
			if (!visited[i])
				bfs(i);	
		for (int i=0;i<upd.size();i++)
		{
			AdjList[upd[i].first].push_back(upd[i].second);
			AdjList[upd[i].second].push_back(upd[i].first);
		}	
		top = 0;
		for (int i=1;i<=n;i++)
			visited[i] = false;
		for (int i=1;i<=n;i++)
			if (!visited[i])
				dfs(i,++top);				
		for (int i=1;i<=4*n;i++)
			Tree_2[i].f[0] = Tree_2[i].f[1] = ii(-1,-1);
		for (int i=1;i<=n;i++)
			for (int j=0;j<Q[i].size();j++)
				update_2(1,1,n,i,Q[i][j].first,Q[i][j].second);
	}
	for (int i=1;i<=n;i++)
		visited[i] = false;
	cal_res(1);
	cout << res;
}	