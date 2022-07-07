#include<bits/stdc++.h>
using namespace std;

int N, a, b, vis[2001], w=0, czy[2001], wsk;
vector<int> kolej;
vector<pair<int, int> > kraw[2001], GT[2001]; //first->nastêpnik   second->mex

void dfs(int v)
{
	vis[v]++;
	
	for(int i=0; i<kraw[v].size(); i++)
	{
		if(vis[kraw[v][i].first]==0)
		dfs(kraw[v][i].first);
	}
	
	kolej.push_back(v);
}

void gothru(int v)
{
	int count=0;
	for(int i=0; i<GT[v].size(); i++)
	{
		czy[GT[v][i].second]++;
		while(czy[wsk]>0)
		{
			wsk++;
			count++;
		}
		w=max(w,wsk-1);
		gothru(GT[v][i].first);
		czy[GT[v][i].second]--;
		wsk-=count;
		count=0;	
	}
}

int main()
{
	cin>>N;
	
	for(int i=1; i<=2*N; i++)
	{
		cin>>a>>b;
		kraw[a].push_back({b,i/2});
		GT[b].push_back({a,i/2});
	}
	
	for(int i=1; i<=N; i++)
	{
		if(vis[i]==0)
		dfs(i);
	}
	
	for(int i=1; i<=N; i++)
	vis[i]=0;
	
	for(int i=0; i<=N-1; i++)
	{
		if(kraw[kolej[i]].size()==0)
		gothru(kolej[i]);
	}
	
	cout<<w;
}
