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

int n, m, a, b, vis[1000001], nrscc[1000001], nrbud[1000001], idx, maxw[1000001], minw[1000001], bud, wart[1000001], ans, odl[1000001], maksodl[1000001], maksidx[1000001];

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
/*
void dfs4(int v)
{
	vis[v]++;
	
	for(int i=0; i<GTscc[v].size(); i++)
	{
		odl[v]=max(odl[v], odl[GTscc[v][i]]+1);
	}
	
	if(odl[v]>maksodl[nrbud[v]])
	{
		maksodl[nrbud[v]]=odl[v];
		maksidx[nrbud[v]]=v;
		ans=max(ans,maksodl[nrbud[v]]);
	}
	
	for(int i=0; i<grafscc[v].size(); i++)
	{
		if(vis[grafscc[v][i]]==0)
		dfs4(grafscc[v][i]);
	}
}
*/
void dfsb(int v)
{
	vis[v]=1;
	nrbud[v]=bud;
	
	for(int i=0; i<grafscc[v].size(); i++)
	{
		if(vis[grafscc[v][i]]==0)
		{
			dfsb(grafscc[v][i]);
		}
	}
	
	for(int i=0; i<GTscc[v].size(); i++)
	{
		if(vis[GTscc[v][i]]==0)
		{
			dfsb(GTscc[v][i]);
		}
	}	
}

void dfs5(int v, int w)
{
	vis[v]=1;
	wart[v]=w;
	
	for(int i=0; i<grafscc[v].size(); i++)
	{
		if(vis[grafscc[v][i]]==0)
		dfs5(grafscc[v][i],w);
	}
	
	for(int i=0; i<GTscc[v].size(); i++)
	{
		if(vis[GTscc[v][i]]==0)
		dfs5(GTscc[v][i],w+1);
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
	
	for(int i=1; i<=idx; i++)
	{
		if(vis[i]==0)
		{
			bud++;
			dfsb(i);
		}	
	}
	/*
	for(int i=1; i<=n; i++)
	vis[i]=0;
	
	
	for(int i=kolejscc.size()-1; i>=0; i--)
	{
		if(vis[kolejscc[i]]==0)
		dfs4(kolejscc[i]);
	}
	
	for(int i=1; i<=n; i++)
	vis[i]=0;
	
	for(int i=1; i<=bud; i++)
	{
		dfs5(maksidx[i],0);
	}
	*/
	cout<<ans+1<<"\n";
	
	for(int i=1; i<=n; i++)
	cout<<wart[nrscc[i]]<<" ";
}
