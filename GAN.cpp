#include<bits/stdc++.h>
using namespace std;

struct wydarzenie{
	char typ; //typ wydarzenia
	int a, b;
};

int n, m, z, w[100001], zap[100001], d, b, ans[150001], ilez, ileztemp, ile;
vector<int> curr;
vector<pair<int,int>> graf[100001];
vector<wydarzenie> wyd;
stack<pair<int*,int>> rollback;

void odp()
{
	set<int> S;
	
	for(int i=0; i<curr.size(); i++)
	S.insert(w[curr[i]]);
	
	ans[ilez+ile]=S.size();
}

void RB()
{
	while(rollback.size())
	{
		*rollback.top().first=rollback.top().second;
		rollback.pop();
	}
}

void dfs(int v, int p)
{	
	int j=0; 
	ile=0;
	while(zap[v])
	{	
		if(wyd[j].typ=='B')
		{
			int* g = &w[wyd[j].a];
			rollback.push({g, w[wyd[j].a]});
			w[wyd[j].a]=wyd[j].b;
		}
		
		if(wyd[j].typ=='Z')
		ile++;
		
		if(wyd[j].typ=='Z' && wyd[j].a==v)
		{
			odp();
			zap[v]--;
		}
		
		j++;
	}
	
	RB();
	
	for(int i=0; i<graf[v].size(); i++)
	{
		if(graf[v][i].first!=p)
		{
			curr.push_back(graf[v][i].second);
			dfs(graf[v][i].first,v);
			curr.pop_back();
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m>>z;
	
	d=ceil(sqrt(z));
	
	for(int i=1; i<=n-1; i++)
	{
		int a, b, c;
		
		cin>>a>>b>>c;
		
		graf[a].push_back({b,i});
		graf[b].push_back({a,i});
		w[i]=c;
	}
	
	b=d;
	
	for(int i=1; i<=z; i++)
	{
		char c;
		cin>>c;
		
		if(c=='B')
		{
			int a, b;
			cin>>a>>b;
			
			wydarzenie W;
			W.typ=c;
			W.a=a; W.b=b;
			wyd.push_back(W);
		}
		else if(c=='Z')
		{
			int a;
			cin>>a;
			
			ileztemp++;
			zap[a]++;
			wydarzenie W;
			W.typ=c;
			W.a=a; W.b=0;
			wyd.push_back(W);
		}
		
		if(i==b || i==z)
		{
			dfs(1,1);
			
			for(int i=0; i<wyd.size(); i++)
			if(wyd[i].typ=='B')
			w[wyd[i].a]=wyd[i].b;
			
			wyd.clear();
			b+=d;
			
			ilez+=ileztemp;
			ileztemp=0;
		}		
	}
	
	for(int i=1; i<=ilez; i++)
	cout<<ans[i]<<"\n";
}
