#include<bits/stdc++.h>
using namespace std;

int n, m, k, tab[501][501], pol[250001][2], rep[250001], sz[250001];
vector<pair<int,int>> zap;
vector<bool> ans;

int find(int v)
{	
	if(rep[v]==v) return v;
	
	return rep[v]=find(rep[v]);
}

void un(int v, int u)
{
	if(v==u)
	return;
	
	v=find(v);
	u=find(u);
	
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

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(0); cout.tie(0);
	
	cin>>n>>m>>k;
	
	for(int i=1; i<=n; i++)
	for(int j=1; j<=m; j++)
	{
		tab[i][j]=((i-1)*m+j);
		rep[((i-1)*m+j)]=((i-1)*m+j);
		sz[((i-1)*m+j)]=1;
	}
	
	for(int i=0; i<k; i++)
	{
		int a, b, c, d;
		cin>>a>>b>>c>>d;
		
		int x=min(tab[a][b],tab[c][d]), y=max(tab[a][b],tab[c][d]);
		
		//cout<<x<<" "<<y<<"\n";
		
		zap.push_back({x,y});
		
		if(y-x==1)
		{
			pol[x][0]=1;
		}
		if(y-x==m)
		{
			pol[x][1]=1;
		}
	}
	for(int i=1; i<=n*m; i++)
	{
		if(pol[i][0]==0 && i%m!=0)
		{
			//cout<<i<<" "<<i+1<<"\n";
			un(i,i+1);
		}
		if(pol[i][1]==0 && i<=m*(n-1))
		{
			//cout<<i<<" "<<i+m<<"\n";
			un(i,i+m);
		}
	}
	
	/*
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		cout<<tab[i][j]<<" ";
		cout<<"\n";
	}
	
	for(int i=1; i<=n*m; i++)
	cout<<rep[i]<<"  ";
	*/
	
	for(int i=zap.size()-1; i>=0; i--)
	{
		if(find(zap[i].first) == find(zap[i].second))
		ans.push_back(true);
		else
		ans.push_back(false);
		
		un(zap[i].first, zap[i].second);
	}
	
	for(int i=ans.size()-1; i>=0; i--)
	if(ans[i])
	cout<<"TAK\n";
	else
	cout<<"NIE\n";
	
}
