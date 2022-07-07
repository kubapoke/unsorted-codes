#include<bits/stdc++.h>
using namespace std;

int n, a, b, p, q, ans;
int tab[1001][1001], vis[1001];
vector<int> graf[1001];

/*
11
1 2
2 3
2 4
2 5
4 6
6 9
6 10
5 7
5 8
8 11
10
2 6
11 2
9 3
6 11
11 9
3 11
9 10
1 2
2 1
2 2
*/

void found(int v, int val)
{
	vis[v]=1;
	
	tab[p][v]=val;
	for(int i=0; i<graf[v].size(); i++)
	{
		if(vis[graf[v][i]]==0)
		found(graf[v][i],val+1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>n;
	
	for(int i=1; i<=n-1; i++)
	{
		cin>>a>>b;
		
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	
	for(int i=1; i<=n; i++)
	{
		if(graf[i].size()==1)
		{
			p++;
			found(i,0);
		}
		
		for(int i=1; i<1001; i++)
		vis[i]=0;
	}
	
	cin>>q;
	
	for(int i=1; i<=q; i++)
	{
		ans=0;
		cin>>a>>b;
		int ans=0;
		for(int j=1; j<=p; j++)
		{
			if(tab[j][a]>tab[j][b])
			ans=max(ans,tab[j][a]);
		}
		cout<<ans<<"\n";
	}
}
