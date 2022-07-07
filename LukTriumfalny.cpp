#include<bits/stdc++.h>
using namespace std;

int n, a, b, dis[300001], iledis[300001], sum, ans;
vector<int> graf[300001];

void dfs(int v, int p)
{
	if(v!=1)
	dis[v]=dis[p]+1;
	iledis[dis[v]]++;
	
	for(int i=0; i<graf[v].size(); i++)
	if(graf[v][i]!=p)
	dfs(graf[v][i],v);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	for(int i=0; i<n-1; i++)
	{
		cin>>a>>b;
		
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	
	dfs(1,1);
	
	//for(int i=1; i<=n; i++)
	//cout<<i<<": "<<dis[i]<<"\n";
	
	for(int i=1; i<=300000; i++)
	{
		sum+=iledis[i];
		
		int currcheck=sum/i;
		
		if(sum%i)
		currcheck++;
		
		ans=max(ans,currcheck);
	}
	
	cout<<ans;
}
