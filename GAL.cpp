#include<bits/stdc++.h>
using namespace std;

const long long INF=1e18;
long long n, m, k, a, b, c, ans=INF, vis[21], ct, dp[(1<<20)][20], graf[20][20];
int gal[500001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m>>k;
	
	for(int i=1; i<=n; i++)
	cin>>gal[i];
	
	for(int i=0; i<k; i++)
	for(int j=0; j<k; j++)
	graf[i][j]=INF;
	
	for(int i=1; i<=m; i++)
	{
		cin>>a>>b>>c;
		a=gal[a]-1;
		b=gal[b]-1;
		if(a!=b)
		{
			graf[a][b]=min(graf[a][b],c);
			graf[b][a]=min(graf[b][a],c);
		}
	}
	
	for(int i=0; i<(1<<k); i++)
	for(int j=0; j<k; j++)
	{
		dp[i][j]=INF;
	}
	
	for(int i=0; i<k; i++)
	dp[(1<<i)][i]=0;
	
	for(int i=0; i<(1<<k); i++)
	for(int j=0; j<k; j++)
	{
		//cout<<bitset<8>(i)<<" "<<j<<": "<<dp[i][j]<<"\n";
		
		if(!(i & (1<<j)) || dp[i][j]==INF)
		continue;
		
		for(int v=0; v<k; v++)
		if(!(i & (1<<v)))
		dp[i+(1<<v)][v]=min(dp[i+(1<<v)][v],dp[i][j]+graf[j][v]);
	}
	
	for(int i=0; i<k; i++)
	{
		ans=min(ans,dp[(1<<k)-1][i]);
	}
	
	if(ans==INF)
	cout<<"NIE";
	else cout<<ans;
	
	//cout<<ans;
}
