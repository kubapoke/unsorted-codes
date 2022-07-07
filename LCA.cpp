#include<bits/stdc++.h>
#define N 100001
#define log 18
using namespace std;

int lca[log][N], preord[N], postord[N], idx, n, a, b;
vector<int> graf[N];

void dfs(int v, int p)
{
	lca[0][v]=p;
	preord[v]=++idx;
	
	for(int i=0; i<graf[v].size(); i++)
	if(graf[v][i]!=p)
	dfs(graf[v][i],v);
	
	postord[v]=++idx;
}

bool anc(int v, int u)
{
	if(preord[v]<preord[u]&&postord[v]>postord[u] || v==u)
	return true;
	
	return false;
}

int getlca(int v, int u)
{
	if(anc(v,u)) return v;
	if(anc(u,v)) return u;
	
	for(int i=log-1; i>=0; i--)
	{
		if(!anc(lca[i][v],u))
		v=lca[i][v];
	}
	
	return lca[0][v];
}

int main()
{
	cin>>n;
	
	for(int i=0; i<n-1; i++)
	{
		int a, b;
		cin>>a>>b;
		
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	
	dfs(1,1);
	
	for(int i=1; i<log; i++)
	for(int v=1; v<=n; v++)
	lca[i][v]=lca[i-1][lca[i-1][v]];
	
	cin>>a>>b;
	
	cout<<getlca(a,b);
}
