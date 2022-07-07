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

/*
12 14
2 1
9 2
3 4
9 3
5 3
5 4
9 5
8 9
9 12
10 12
11 10
7 11
7 6
6 11
*/

int n, m, a, b, vis[1000001], nrscc[1000001], idx, wart[1000001], ans;

vector<int> graf[1000001], GT[1000001], kolej, kolejscc, grafscc[1000001], GTscc[1000001];

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

void dfs3(int v)
{
	vis[v]=1;
	
	for(int i=0; i<grafscc[v].size(); i++)
	if(vis[grafscc[v][i]]==0)
	dfs3(grafscc[v][i]);
	
	kolejscc.push_back(v);
}

void dfsx(int v)
{
	vis[v]=1;
	
	if(!grafscc[v].empty())
	wart[v]=1e9;
	
	for(int i=0; i<grafscc[v].size(); i++)
	{
		wart[v]=min(wart[v],wart[grafscc[v][i]]+1);
	}
	
	ans=max(ans,wart[v]);
	
	for(int i=0; i<GTscc[v].size(); i++)
	{
		if(vis[GTscc[v][i]]==0)
		dfsx(GTscc[v][i]);
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
	vis[i]=0;
	
	
	
	for(int i=kolej.size()-1; i>=0; i--)
	{
		if(vis[kolej[i]]==0)
		{
			idx++;
			dfs2(kolej[i]);
		}
	}
	
	for(int i=1; i<=n; i++)
	{
		for(int j=0; j<graf[i].size(); j++)
		if(nrscc[i]!=nrscc[graf[i][j]])
		{
			grafscc[nrscc[i]].push_back(nrscc[graf[i][j]]);
			GTscc[nrscc[graf[i][j]]].push_back(nrscc[i]);
		}
	}
	
	
	for(int i=1; i<=n; i++)
	vis[i]=0;
	
	for(int i=1; i<=idx; i++)
	{
		if(vis[i]==0)
		dfs3(i);
	}
	
	for(int i=1; i<=n; i++)
	vis[i]=0;
	
	for(int i=0; i<=kolejscc.size()-1; i++)
	{
		if(vis[kolejscc[i]]==0)
		{
			dfsx(kolejscc[i]);
		}	
	}

	cout<<ans+1<<"\n";
	
	for(int i=1; i<=n; i++)
	cout<<wart[nrscc[i]]<<" ";
}
