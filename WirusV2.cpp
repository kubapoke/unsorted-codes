#include<bits/stdc++.h>
#define NTREE 524288
using namespace std;

int n, x, g[300001], tree[NTREE*2], par[300001], sp[300001], rsp[300001], idxsp=1, tpar[300001];
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
	par[v]=p;
	
	for(int i=0; i<graf[v].size(); i++)
	{
		if(graf[v][i]!=p)
		{
			dfsinit(graf[v][i], v);
		}
	}
}

bool smaller_tree(int v, int u)
{
	stack<int> a, b;
	a.push(v);
	b.push(u);
	tpar[u]=v;
	tpar[v]=u;
	int x;
	
	while(a.size() && b.size())
	{
		x=a.top();
		a.pop();
		for(auto n:graf[x])
		{
			if(n!=tpar[x] && sp[x]==sp[n])
			{
				tpar[n]=x;
				a.push(n);
			}
		}
		
		if(a.empty()) break;
		
		x=b.top();
		b.pop();
		for(auto n:graf[x])
		{
			if(n!=tpar[x] && sp[x]==sp[n])
			{
				tpar[n]=x;
				b.push(n);
			}
		}	
	}
	
	if(a.empty()) return true;
	
	return false;
}

void dfs(int v, int p, int z)
{
	rsp[idxsp]++;
	rsp[z]--;
	
	for(auto n: graf[v])
	{
		if(n!=p && sp[v]==sp[n])
		dfs(n,v,z);
	}
	
	sp[v]=idxsp;
}

int odp(int v)
{
	bool m=smaller_tree(v,par[v]);
	
	idxsp++;
	
	if(m)
	dfs(v,par[v],sp[par[v]]);
	else
	dfs(par[v],v,sp[v]);
	
	cout<<rsp[sp[v]]<<"\n";
	return rsp[sp[v]];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>x;
	
	for(int i=1; i<=n-2; i++)
	cin>>g[i];
	
	sp[1]=1;
	
	for(int i=2; i<=n; i++)
	{
		int a, b;
		cin>>a>>b;
		
		graf[a].push_back(b);
		graf[b].push_back(a);
		
		ins(i,1);
		
		sp[i]=1;
	}
	
	rsp[1]=n;
	
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
