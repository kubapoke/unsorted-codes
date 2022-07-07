#include<bits/stdc++.h>
using namespace std;

int N, a, b, w, czy[2001], wsk;
vector<pair<int, int> > kraw[2001], GT[2001]; //first->nastêpnik   second->mex
vector<int> kolej;
bool vis[2001];


void dfs(int v) //postorder
{
	vis[v]=true;
	
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
		w=max(w,wsk);
		
		//cout<<v<<" -> "<<GT[v][i].first<<" wartosc "<<GT[v][i].second<<"\n"<<wsk<<"\n\n";
		
		gothru(GT[v][i].first);
		
		czy[GT[v][i].second]--;
		wsk-=count;
		count=0;	
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>N;
	
	for(int i=0; i<=2*N-1; i++)
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
	
	for(int i=1; i<=N; i++)
	{
		if(kraw[i].size()==0)
		gothru(i);
	}
	
	cout<<w;
}
