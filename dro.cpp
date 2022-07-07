#include<bits/stdc++.h>
using namespace std;

const int x=50001;
int m, n, a, b, vis[x], gdzie[x], l, wej[x], odp[x], z, sz[x];
vector<int> graf[x], grafr[x], grafscc[x], order;
pair<int,int> krw[2*x];
queue<int> Q;

void preorder(int v)
{
	vis[v]=1;
	for(int i=0; i<graf[v].size(); i++)
	{
		if(vis[graf[v][i]]==0)
		preorder(graf[v][i]);
	}
	order.push_back(v);
}

void scc(int v)
{
	vis[v]=1;
	
	gdzie[v]=l;
	
	sz[l]++;
	
	for(int i=0; i<grafr[v].size(); i++)
	{
		if(vis[grafr[v][i]]==0)
		scc(grafr[v][i]);
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
		grafr[b].push_back(a);
		krw[i].first=a;
		krw[i].second=b;
	}
	
	for(int i=1; i<=n; i++)
	{
		if(vis[i]==0)
		preorder(i);
	}
	
	for(int i=1; i<=n; i++)
	vis[i]=0;
	
	for(int i=order.size()-1; i>=0; i--)
	{
		if(vis[i]==0)
		{
			l++;
			scc(i);
		}
	}
	
	order.clear();
	
	for(int i=1; i<=m; i++)
	{
		if(gdzie[krw[i].first]!=gdzie[krw[i].second])
		{
			grafscc[krw[i].first].push_back(krw[i].second);
			wej[krw[i].second]++;
		}
	}
	
	for(int i=1; i<=l; i++)
	{
		if(wej[i]==0)
		Q.push(i);
	}
	
	while(Q.size())
	{
		z=Q.front();
		Q.pop();
		order.push_back(z);
		
		for(int i=0; i<grafscc[z].size(); i++)
		{
			wej[grafscc[z][i]]--;
			if(wej[grafscc[z][i]]==0)
			Q.push(grafscc[z][i]);
		}
	}
	
	for(int i=order.size()-1; i>=0; i--)
	{
		odp[order[i]]=sz[order[i]]-1;
		
		for(int j=0; j<grafscc[order[i]].size(); j++)
		{
			odp[order[i]]+=odp[grafscc[order[i]][j]];
		}
	}
	
	for(int i=1; i<=n; i++) 
	cout<<odp[gdzie[i]]<<"\n";
}
