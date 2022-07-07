#include<bits/stdc++.h>
#define X 150000
using namespace std;

int t, k, n, kol[150001], nscc[600001], vis[600001], idx;
vector<int> graf[600001], GT[600001];
stack<int> S;

void dfs(int v)
{
	vis[v]=1;
	
	for(int i=0; i<graf[v].size(); i++)
	if(vis[graf[v][i]]==0)
	dfs(graf[v][i]);
	
	S.push(v);
}

void dfscc(int v)
{
	vis[v]=1;
	nscc[v]=idx;
	
	for(int i=0; i<GT[v].size(); i++)
	if(vis[GT[v][i]]==0)
	dfscc(GT[v][i]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>t;
	
	for(int P=0; P<t; P++)
	{
		map<pair<int,int>, vector<int>> m;
		map<pair<int,int>, vector<int>>::iterator it;
		
		for(int i=0; i<600001; i++)
		{
			graf[i].clear();
			GT[i].clear();
		}
		
		while(!S.empty())
		S.pop();
		
		fill(vis,vis+600001,0);
		
		/////
		
		cin>>n>>k;
		for(int i=1; i<=n; i++)
		{
			cin>>kol[i];
			if(i>1)
			m[{kol[i-1],kol[i]}].push_back(i-1);
		}
		
		graf[1+X].push_back(1); graf[1+X].push_back(1); GT[1].push_back(1+X); GT[1].push_back(1+X);
		graf[n-1+X].push_back(n-1); graf[n-1+X].push_back(n-1); GT[n-1].push_back(n-1+X); GT[n-1].push_back(n-1+X);
		
		for(int i=1; i<=n-2; i++)
		{
			graf[i+X].push_back(i+1); GT[i+1].push_back(i+X);
			graf[i+1+X].push_back(i); GT[i].push_back(i+1+X);
		}
		
		for(it=m.begin(); it!=m.end(); it++)
		{
			vector<int> v=it->second;
			
			graf[v[0]+2*X].push_back(v[0]); GT[v[0]].push_back(v[0]+2*X);
			
			for(int i=0; i<v.size(); i++)
			{
				graf[v[i]].push_back(v[i]+2*X); GT[v[i]+2*X].push_back(v[i]);
				
				if(i>0)
				{
					graf[v[i]].push_back(v[i-1]+3*X); GT[v[i-1]+3*X].push_back(v[i]);
					graf[v[i-1]+2*X].push_back(v[i]+X); GT[v[i]+X].push_back(v[i-1]+2*X);
					graf[v[i-1]+2*X].push_back(v[i]+2*X); GT[v[i]+2*X].push_back(v[i-1]+2*X);
				} 
			}
		}
		
		for(int i=1; i<=n; i++)
		{
			if(vis[i]==0)
			dfs(i);
			
			if(vis[i+X]==0)
			dfs(i+X);
			
			if(vis[i+2*X]==0)
			dfs(i+2*X);
			
			if(vis[i+3*X]==0)
			dfs(i+3*X);
		}
		
		fill(vis,vis+600001,0);
		
		while(S.size())
		{
			if(vis[S.top()]==0)
			{
				idx++;
				dfscc(S.top());
			}
			
			S.pop();
		}
		
		bool b=true;
		
		for(int i=1; i<=n; i++)
		{
			cout<<i<<": "<<nscc[i]<<" "<<nscc[i+X]<<" "<<nscc[i+2*X]<<" "<<nscc[i+3*X]<<"\n";
			if(nscc[i]==nscc[i+X] || nscc[i+2*X]==nscc[i+3*X])
			b=false;
		}
		
		if(b==true)
		cout<<"TAK\n";
		else
		cout<<"NIE\n";
	}
}
