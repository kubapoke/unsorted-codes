#include<bits/stdc++.h>
using namespace std;

int rep[500001], sz[500001], lca[20][500001], d[500001], dis[500001], pl;
vector<pair<int,int>> graf[500001];

int find(int v)
{
	if(rep[v]==v) return v;
	return rep[v]=find(rep[v]);
}

void uni(int v, int u)
{
	if(v==u) return;
	
	v=find(v); u=find(u);
	
	if(sz[v]>sz[u])
	{
		sz[v]+=sz[u];
		rep[u]=v;
	}
	else
	{
		sz[u]+=sz[v];
		rep[v]=u;
	}
}

int getlca(int v, int u)
{
	int skok=524288, l=19;
	
	if(d[v]<d[u])
	swap(v,u);
	
	while(d[v]!=d[u])
	{
		while(d[v]-d[u]<skok)
		{
			skok/=2;
			l--;
		}
		
		v=lca[l][v];
	}
	
	if(v==u)
	return v;
	
	for(l=19; l>=0; l--)
	{
		if(lca[l][v]!=lca[l][u])
		{
			v=lca[l][v]; u=lca[l][u];
		}
	}
	
	return lca[0][v];
}

void init(int N, int S)
{
	for(int i=1; i<=N; i++)
	{
		rep[i]=i;
		sz[i]=1;
		d[i]=1;
		dis[i]=0;
		
		lca[0][i]=i;
		
		for(int j=1; j<20; j++)
		lca[j][i]=lca[j-1][lca[j-1][i]];
	}
}

void dfs(int v, int b)
{
	d[v]=d[b]+1;
	
	lca[0][v]=b;
	
	for(int j=1; j<20; j++)
	lca[j][v]=lca[j-1][lca[j-1][v]];
	
	for(int i=0; i<graf[v].size(); i++)
	{
		if(graf[v][i].first!=b)
		{
			dis[graf[v][i].first]=dis[v]+graf[v][i].second;
			dfs(graf[v][i].first,v);
		}
	}
}

void build(int x, int y, int m)
{
	int setx=find(x), sety=find(y);
	
	if(sz[setx]<sz[sety])
	swap(x,y);
	
	uni(x,y);
	graf[x].push_back({y,m});
	graf[y].push_back({x,m});
	
	dis[y]=dis[x]+m;
	
	//³¹czymy y do x
	
	dfs(y,x);
}

int path(int x, int y)
{
	return (dis[x]+dis[y]-(2*dis[getlca(x,y)]));
}
