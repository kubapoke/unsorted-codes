#include<bits/stdc++.h>
using namespace std;

long long Z, n, s[5001], p[5001], c[5001], ans;
vector<long long> pod[5001];

bool dfs(int v)
{	
	bool b=false;
	
	long long add=0;
	
	for(int i=0; i<pod[v].size(); i++)
	{
		if(dfs(pod[v][i]))
		b=true;
	}
	
	if(s[v] && v!=1)
	b=true;
	
	s[p[v]]+=min(s[v],c[v]);
	s[v]-=min(s[v],c[v]);
	
	return b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>Z;
	
for(int mmm=0; mmm<Z; mmm++)
{
	cin>>n;
	
	for(int i=1; i<=n; i++)
	pod[i].clear();
	for(int i=2; i<=n; i++)
	cin>>s[i];
	for(int i=2; i<=n; i++)
	{
		cin>>p[i];
		pod[p[i]].push_back(i);
	}
	for(int i=2; i<=n; i++)
	cin>>c[i];
	
	ans=0;
	
	while(dfs(1))
	ans++;
	
	cout<<ans<<"\n";
}	
}
