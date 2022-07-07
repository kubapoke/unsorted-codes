#include<bits/stdc++.h>
using namespace std;

/*
7 9
6 7
4 2
3 5
4 6
1 6
3 3
6 2
3 5
2 6
*/

int n, m, a, b, vis[1000001], nrscc[1000001], nrbud[1000001], idx, maxw[1000001], minw[1000001], bud, wart[1000001], ans;

vector<int> graf[1000001], GT[1000001], kolej;

void dfs1(int v)
{
	vis[v]=1;
	
	for(int i=0; i<graf[v].size(); i++)
	if(vis[graf[v][i]]==0)
	dfs1(graf[v][i]);
	
	kolej.push_back(v);
}

void dfs2(int v)
{
	vis[v]=1;
	
	nrscc[v]=idx;
	
	for(int i=0; i<GT[v].size(); i++)
	if(vis[GT[v][i]]==0)
	dfs2(GT[v][i]);
}

void dfs3(int v, int w)
{
	vis[v]=1;
	nrbud[v]=bud;
	
	wart[v]=w;
	//cout<<v<<" "<<wart[v]<<"  \n";
	
	maxw[bud]=max(maxw[bud],w);
	minw[bud]=min(minw[bud],w);
	
	for(int i=0; i<graf[v].size(); i++)
	{
		if(vis[graf[v][i]]==0)
		{
			if(nrscc[v]==nrscc[graf[v][i]])
			dfs3(graf[v][i],w);
			else
			dfs3(graf[v][i],w-1);
		}
	}
	
	for(int i=0; i<GT[v].size(); i++)
	{
		if(vis[GT[v][i]]==0)
		{
			if(nrscc[v]==nrscc[GT[v][i]])
			dfs3(GT[v][i],w);
			else
			dfs3(GT[v][i],w+1);
		}
	}
	
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>n>>m;
	
	for(int i=1; i<=m; i++)
	{
		cin>>a>>b;
		
		graf[a].push_back(b);
		GT[b].push_back(a);
	}
	
	for(int i=1; i<=n; i++)
	{
		if(vis[i]==0)
		dfs1(i);
	}
	
	for(int i=1; i<=n; i++)
	{
		vis[i]=0;
		maxw[i]=-1e9;
		minw[i]=1e9;
	}
	
	
	for(int i=kolej.size()-1; i>=0; i--)
	{
		if(vis[kolej[i]]==0)
		{
			idx++;
			dfs2(kolej[i]);
		}
	}
	
	for(int i=1; i<=n; i++)
	vis[i]=0;
	
	for(int i=1; i<=n; i++)
	{
		bud++;
		if(vis[i]==0)
		dfs3(i,0);
	}
	
	for(int i=1; i<=bud; i++)
	ans=max(ans,maxw[i]-minw[i]+1);
	
	cout<<ans<<"\n";
	
	for(int i=1; i<=n; i++)
	{
		cout<<wart[i]-minw[nrbud[i]]<<" ";
	}
}
