#include<bits/stdc++.h>
using namespace std;

int n, m, a, b, vis[100001];
string s, val[100001];
bool czy[100001];
pair<int,string> nast[100001];
vector<pair<int,string>> graf[100001], grafv[100001];
queue<int> postorder;

void vdfs(int v, int p)
{
	vis[v]=1;
	for(int i=0; i<grafv[v].size(); i++)
	if(grafv[v][i].first!=p&&vis[grafv[v][i].first]==0)
	vdfs(grafv[v][i].first,v);
	czy[v]=1;
}

void dfs(int v, int p)
{
	vis[v]=1;
	for(int i=0; i<graf[v].size(); i++)
	if(graf[v][i].first!=p&&vis[graf[v][i].first]==0&&czy[v]==1)
	dfs(graf[v][i].first,v);
	postorder.push(v);
}

int main()
{
	cin>>n>>m;
	
	for(int i=0; i<m; i++)
	{
		cin>>a>>b>>s;
		graf[a].push_back({b,s});
		grafv[b].push_back({a,s});
	}
	
	vdfs(n,n);
	for(int i=1; i<=n; i++)
	vis[i]=0;
	dfs(1,1);
	
	while(postorder.size())
	{
		int v=postorder.front();
		postorder.pop();
		for(int i=0; i<grafv[v].size(); i++)
		{
			string x=grafv[v][i].second;
			string y=val[v];
			string z=x.append(y);
			
			if(val[grafv[v][i].first]==""||val[grafv[v][i].first]>z)
			{
				val[grafv[v][i].first]=z;
				nast[grafv[v][i].first]={v,grafv[v][i].second};
			}
		}
	}
	
	string ans;
	int i=1;
	
	while(nast[i].first!=0)
	{
		ans.append(nast[i].second);
		i=nast[i].first;
	}
	
	cout<<ans;
}
