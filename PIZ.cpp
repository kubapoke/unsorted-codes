#include<bits/stdc++.h>
using namespace std;

int n, m, k;
long long dis[1001][1001], len[1001][1001], late[1001][1001];
vector<pair<int,int>> graf[1001];

struct ST{
	long long s,u,t;
}zam[1001];

void dijkstra(int d)
{
	priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> Q;
	Q.push({0,d});
	dis[d][d]=0;
	
	while(!Q.empty())
	{
		long long distance=Q.top().first;
		int v=Q.top().second;
		Q.pop();
		
		if(distance>dis[d][v])
		continue;
		
		for(int i=0; i<graf[v].size(); i++)
		{
			if(dis[d][graf[v][i].first] > dis[d][v]+graf[v][i].second)
			{
				dis[d][graf[v][i].first]=dis[d][v]+graf[v][i].second;
				Q.push({dis[d][graf[v][i].first],graf[v][i].first});
			}
		}
	}
}

bool check(long long t)
{
	long long dp[k+1];
	dp[0]=0;
	for(int i=1; i<=k; i++)
	dp[i]=1e18;
	
	for(int i=1; i<=k; i++)
	{
		for(int j=0; j<i; j++)
		{
			if(late[j+1][i]+max(dp[j],zam[i].t)<=t)
			{
				//cout<<late[j+1][i]<<" "<<max(dp[j],zam[j+1].t)<<" "<<zam[j+1].t<<"\n";
				//cout<<max(dp[j],zam[j+1].t)<<" "<<len[j+1][i]<<"\n";
				dp[i]=min(dp[i], max(dp[j],zam[i].t)+len[j+1][i]);
				//cout<<i<<" "<<dp[i]<<"\n";
			}
		}
		
		if(dp[i]==1e18)
		return false;
	}
	
	//cout<<t<<"\n";
	//for(int i=1; i<=k; i++)
	//cout<<dp[i]<<" ";
	//cout<<"\n";
	
	return true;
}

int main()
{
	cin>>n>>m;
	
	for(int i=0; i<m; i++)
	{
		int v, u, c;
		cin>>v>>u>>c;
		graf[v].push_back({u,c});
		graf[u].push_back({v,c});
	}
	
	for(int i=1; i<=n; i++)
	for(int j=1; j<=n; j++)
	dis[i][j]=1e18;
	
	for(int i=1; i<=n; i++)
	dijkstra(i);
	
	cin>>k;
	
	for(int i=1; i<=k; i++)
	{
		int s, u, t;
		cin>>s>>u>>t;
		zam[i].s=s;
		zam[i].u=u;
		zam[i].t=t;
	}
	
	for(int i=1; i<=k; i++)
	for(int j=i; j<=k; j++)
	{
		if(i==j)
		{
			len[i][j]=2*dis[1][zam[i].u];
			late[i][j]=dis[1][zam[i].u]-zam[i].s;
		}
		else
		{
			len[i][j]=len[i][j-1]-dis[1][zam[j-1].u]+dis[zam[j].u][zam[j-1].u]+dis[1][zam[j].u];
			late[i][j]=max(late[i][j-1], len[i][j]-dis[1][zam[j].u]-zam[j].s);
		}
		
	}
	
	//(int i=1; i<=n; i++)
	//for(int j=1; j<=n; j++)
	//cout<<i<<" "<<j<<" "<<dis[i][j]<<"\n";
	
	//for(int i=1; i<=k; i++)
	//for(int j=i; j<=k; j++)
	//cout<<i<<" "<<j<<" "<<len[i][j]<<"\n";
	
	//for(int i=1; i<=k; i++)
	//for(int j=i; j<=k; j++)
	//cout<<i<<" "<<j<<" "<<late[i][j]<<"\n";
	
	long long st=1, sr, ed=1152921504606846976;
	
	//cout<<st<<" "<<ed;
	
	while(1)
	{
		if(st==ed)
		{
			cout<<max(st,1ll*0);
			return 0;
		}
		
		//cout<<sr<<"\n";
		
		sr=(st+ed)/2;
		
		//cout<<check(sr)<<"\n";
		
		if(check(sr)==false)
		st=sr+1;
		else
		ed=sr;
	}
}
