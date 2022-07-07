#include<bits/stdc++.h>
#define log 18
#define N 100001
using namespace std;

int lca[log][N], lcamax[log][N], preord[N], postord[N], idx, n, a, b, c;
vector<pair<int,int>> graf[N];

void dfs(int v, int p, int w)
{
	lca[0][v]=p; lcamax[0][v]=w;
	preord[v]=++idx;
	
	for(int i=0; i<graf[v].size(); i++)
	if(p!=graf[v][i].first)
	dfs(graf[v][i].first, v, graf[v][i].second);
	
	postord[v]=++idx;
}

bool anc(int v, int u)
{
	if((preord[v]<preord[u]&&postord[v]>postord[u])||v==u)
	return true;
	return false;
}

int getlca(int v, int u)
{
	if(anc(v,u)) return v;
	if(anc(u,v)) return u;
	
	for(int i=log-1; i>=0; i--)
	if(!anc(lca[i][v],u))
	v=lca[i][v];
	
	return lca[0][v];
}

int getlcamax(int v, int u)
{
	int ans=0;
	
	for(int i=log-1; i>=0; i--)
	{
		if(!anc(lca[i][v],u))
		{
			ans=max(ans,lcamax[i][v]);
			v=lca[i][v];
		}
		if(!anc(lca[i][u],v))
		{
			ans=max(ans,lcamax[i][u]);
			u=lca[i][u];
		}
	}
	
	if(anc(v,u))
	return max(ans,lcamax[0][u]);
	if(anc(u,v))
	return max(ans,lcamax[0][v]);
	
	return max(ans, max(lcamax[0][u],lcamax[0][v]));
}

int main()
{
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>a>>b>>c;
		
		graf[a].push_back({b,c});
		graf[b].push_back({a,c});
	}
	
	dfs(1,1,0);
	
	for(int i=1; i<log; i++)
	{
		for(int v=1; v<=n; v++)
		{
			lca[i][v]=lca[i-1][lca[i-1][v]];
			lcamax[i][v]=max(lcamax[i-1][v], lcamax[i-1][lca[i-1][v]]);
		}
	}
}
