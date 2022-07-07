#include<bits/stdc++.h>
#define INF 1e18
using namespace std;
typedef long long ll;

ll n, m, a, b, c, d, idx, p, k;
vector<int> graf[1000001];
int ide[1002][1002];
string tab[1002];
vector<ll> odl(1000001,INF), rodl(1000001,INF);
priority_queue<pair<ll,int>> Q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m>>a>>b>>c>>d;
	
	for(int j=1; j<=n; j++)
	{
		cin>>tab[j];
		for(int i=0; i<m; i++)
		{		
			idx++;
			ide[j][i]=idx;
			if(i==b-1&&j==a)
			p=idx;
			if(i==d-1&&j==c)
			k=idx;
			if(tab[j][i]=='.')
			{
				if(i>0)
				{
					if(tab[j][i-1]=='.')
					{
						graf[ide[j][i]].push_back(ide[j][i-1]);
						graf[ide[j][i-1]].push_back(ide[j][i]);
					}/*
					else if(i>1)
					{
						if(tab[j][i-2]=='.')
						{
							graf[ide[j][i]].push_back(ide[j][i-2]);
							graf[ide[j][i-2]].push_back(ide[j][i]);
						}
					}*/
				}
				if(j>1)
				{
					if(tab[j-1][i]=='.')
					{
						graf[ide[j][i]].push_back(ide[j-1][i]);
						graf[ide[j-1][i]].push_back(ide[j][i]);
					}/*
					else if(j>2)
					{
						if(tab[j-2][i]=='.')
						{
							graf[ide[j][i]].push_back(ide[j-2][i]);
							graf[ide[j-2][i]].push_back(ide[j][i]);
						}
					}*/
				}
			}
		}
	}
	
	Q.push({0,p});
	odl[p]=0;
	while(!Q.empty())
	{
		ll dis=Q.top().first*(-1);
		int v=Q.top().second;
		Q.pop();
		if(dis>odl[v]) continue;
		for(int i=0; i<graf[v].size(); i++)
		{
			int u=graf[v][i];
			if(odl[u]>odl[v]+1)
			{
				odl[u]=dis+1;
				Q.push(make_pair(-odl[u],u));
			}
		}
	}
	
	Q.push({0,k});
	rodl[k]=0;
	while(!Q.empty())
	{
		ll dis=Q.top().first*(-1);
		int v=Q.top().second;
		Q.pop();
		if(dis>rodl[v]) continue;
		for(int i=0; i<graf[v].size(); i++)
		{
			int u=graf[v][i];
			if(rodl[u]>rodl[v]+1)
			{
				rodl[u]=dis+1;
				Q.push(make_pair(-rodl[u],u));
			}
		}
	}
	
	//for(int i=1; i<=n*m; i++)
	//cout<<i<<": "<<odl[i]<<"\n";
	//for(int i=1; i<=n*m; i++)
	//cout<<i<<": "<<rodl[i]<<"\n";
	
	long long ans=odl[k];
	
	for(int j=1; j<=n; j++)
	{
		for(int i=0; i<m; i++)
		{
			if(tab[j][i]=='#')
			{
				if(j!=1&&j!=n)
				{
					ans=min(ans,odl[ide[j-1][i]]+rodl[ide[j+1][i]]+1);
					ans=min(ans,rodl[ide[j-1][i]]+odl[ide[j+1][i]]+1);
				}
				if(i!=0&&j!=m-1)
				{
					ans=min(ans,odl[ide[j][i-1]]+rodl[ide[j][i+1]]+1);
					ans=min(ans,rodl[ide[j][i-1]]+odl[ide[j][i+1]]+1);
				}
			}
		}
	}
	
	
	
	if(ans==INF)
	{
		cout<<"NIE";
		return 0;
	}
	cout<<ans+1;
	
}
