#include<bits/stdc++.h>
using namespace std;

long long Z, n, s[5001], p[5001], c[5001];
vector<long long> pod[5001];

long long dfs(long long v)
{	
	long long nextmax=-1, d;
	
	if(v!=1)
	{
		d=(s[v]/c[v]);
		if(s[v]%c[v])
		d++;
	}
	
	for(int i=0; i<pod[v].size(); i++)
	{
		nextmax=max(nextmax, dfs(pod[v][i]));
		s[v]+=s[pod[v][i]];
	}
	
	if(v==1)
	return nextmax;
	
	long long t=(s[v]/c[v]);
	if(s[v]%c[v])
	t++;
	
	if(!d && t)
	t++;
	
	//cout<<v<<" "<<max(nextmax+1, t)<<"\n";
	
	return max(nextmax+1, t);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>Z;
	
for(int mmm=0; mmm<Z; mmm++)
{
	cin>>n;
	
	s[1]=0;
	
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
	
	cout<<dfs(1)<<"\n";
}	
}
