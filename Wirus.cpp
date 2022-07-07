#include<bits/stdc++.h>
#define NTREE 524288
using namespace std;

int n, x, g[300001], w[300001], par[300001], tree[NTREE*2];
vector<int> graf[300001];
set<int> ojc;
set<int>::iterator it;

void ins(int v, int val)
{
	v+=NTREE;
	
	while(v)
	{
		tree[v]+=val;
		v/=2;
	}
}

int getv(int v, int s)
{
	if(v>=NTREE)
	return v-NTREE;
	
	if(tree[v*2]>=s)
	return getv(v*2, s);
	else
	return getv(v*2+1,s-tree[v*2]);
}

void dfsinit(int v, int p)
{
	w[v]=1;
	par[v]=p;
	
	for(int i=0; i<graf[v].size(); i++)
	{
		if(graf[v][i]!=p)
		{
			dfsinit(graf[v][i], v);
			w[v]+=w[graf[v][i]];
		}
	}
}

void sig(int v, int s)
{
	w[v]-=s;
	if(par[v]!=v)
	sig(par[v],s);
}

int odp(int v)
{
	sig(par[v], w[v]);
	par[v]=v;
	ojc.erase(v);
	cout<<w[v]<<"\n";
	return w[v];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>x;
	
	for(int i=1; i<=n-2; i++)
	cin>>g[i];
	
	for(int i=2; i<=n; i++)
	{
		int a, b;
		cin>>a>>b;
		
		graf[a].push_back(b);
		graf[b].push_back(a);
		
		ins(i,1);
	}
	
	dfsinit(1,1);
	
	int y=odp(x);
	ins(x,-1);
	
	for(int i=1; i<=n-2; i++)
	{
		int l=(y+g[i])%(n-i-1)+1;
		
		x=getv(1,l);
		ins(x,-1);
		
		y=odp(x);
	}
}
