#include<bits/stdc++.h>
using namespace std;

void init(int N, int S)
{
	int n, rep[500001], sz[500001];
	vector<pair<int,int>> w[500001]; //para{odleg³oœæ od reprezentanta, reprezentant
	
	for(int i=1; i<=n; i++)
	{
		rep[i]=i;
		sz[i]=1;
		w[i].push_back({0,i});
	}
}

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

void build(int x, int y, int m) 
{
	int setx=find(x), sety=find(y);
	uni(x,y);
	int setz=find(x);
	
	if(setz==setx)
	{
		for(int i=0; i<w[y].size(); i++)
		{
			w[w[y][i].second].push_back({w[y][i].first+m,x});
		}
	}
	else
	{
		for(int i=0; i<w[x].size(); i++)
		{
			w[w[x][i].second].push_back({w[x][i].first+m,y});
		}
	}
}

int path(int x, int y)
{
	int ans1=0, ans2=0, r=rep[x], z;
	
	z=x;
	while(z!=r)
	{
		if(z==y)
		return ans1;
		
		ans1+=w[z][w[z].size()-1].first;
		z=w[z][w[z].size()-1].second;
	}
	
	z=y;
	while(z!=r)
	{
		if(z==x)
		return ans2;
		
		ans2+=w[z][w[z].size()-1].first;
		z=w[z][w[z].size()-1].second;
	}
	
	return ans1+ans2;
}
