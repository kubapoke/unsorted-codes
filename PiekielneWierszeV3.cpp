#include<bits/stdc++.h>
using namespace std;

int m, rep[1001], sz[1001], p[1001], k[1001], it[1001];
vector<int> graf[1001], ans;
queue<int> P[1001], K[1001], E[1001];

int find(int v)
{
	if(rep[v]==v) return v;
	
	return rep[v]=find(rep[v]);
}

void uni(int v, int u)
{
	v=find(v); u=find(u);
	
	if(v==u)
	return;
	
	if(sz[v]>=sz[u])
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

void find_Eulerian_path(int v)
{
	while(it[v]<graf[v].size())
	{
		it[v]++;
		find_Eulerian_path(graf[v][it[v]-1]);
	}
	
	ans.push_back(v);
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(0); cout.tie(0);
	
	cin>>m;
	
	for(int i=1; i<=1000; i++)
	{
		rep[i]=i;
		sz[i]=1;
	}
	
	for(int i=1; i<=m; i++)
	{
		int a, b;
		cin>>a>>b;
		
		graf[a].push_back(b);
		
		p[a]++; k[b]++;
		
		uni(a,b);
	}
	
	for(int i=1; i<=1000; i++)
	{
		if(p[i]>k[i])
		P[find(rep[i])].push(i); //wiêcej wychodzi
		
		if(p[i]<k[i])
		K[find(rep[i])].push(i); //wiêcej wchodzi
		
		if(p[i]==k[i] && p[i])
		E[find(rep[i])].push(i); //tyle samo wychodzi i wchodzi
	}
	
	for(int i=1; i<=1000; i++)
	{
		if(!(P[i].size() + K[i].size() + E[i].size()))
		continue;
		
		if(!(P[i].size() + K[i].size()))
		{
			find_Eulerian_path(E[i].front());
			
			continue;
		}
		
		while(69)
		{
			if(P[i].size()==1 && K[i].size()==1 && p[P[i].front()]-k[P[i].front()]<=1 && k[K[i].front()]-p[K[i].front()]<=1)
			{
				find_Eulerian_path(P[i].front());
				break;
			}
			
			graf[K[i].front()].push_back(P[i].front());
			
			p[K[i].front()]++;
			k[P[i].front()]++;
			
			if(p[K[i].front()]==k[K[i].front()])
			K[i].pop();
			
			if(p[P[i].front()]==k[P[i].front()])
			P[i].pop();
		}
	}
	
	cout<<ans.size()<<"\n";
	
	for(int i=ans.size()-1; i>=0; i--)
	cout<<ans[i]<<" ";
}
