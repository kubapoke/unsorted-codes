#include<bits/stdc++.h>
#define M 1e6
#define INF 1e18
using namespace std;

int n, m, Z, D, a, b, c;
long long dis[2000001];
vector<pair<int,int>> graf[2000001];
priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> PQ;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	
	for(int i=0; i<m; i++)
	{
		int x, y, s;
		cin>>x>>y>>s;
		
		graf[x].push_back({y+1000000,s});
		graf[y].push_back({x+1000000,s});
		graf[x+1000000].push_back({y,s});
		graf[y+1000000].push_back({x,s});
	}
	
	cin>>Z>>D;
	
	for(int i=0; i<=2000000; i++)
	dis[i]=INF;
	
	dis[Z]=0;
	PQ.push({0,Z});
	
	while(!PQ.empty())
	{
		long long distance=PQ.top().first;
		int v=PQ.top().second;
		PQ.pop();
		
		if(distance>dis[v])
		continue;
		
		for(int i=0; i<graf[v].size(); i++)
		{
			if(dis[graf[v][i].first] > dis[v]+graf[v][i].second)
			{
				dis[graf[v][i].first]=dis[v]+graf[v][i].second;
				PQ.push({dis[graf[v][i].first], graf[v][i].first});
			}
		}
	}
	
	if(dis[D]!=INF)
	cout<<dis[D]<<" ";
	else
	cout<<"-1 ";
	
	if(dis[D+1000000]!=INF)
	cout<<dis[D+1000000]<<" ";
	else
	cout<<"-1 ";
	
	
}
