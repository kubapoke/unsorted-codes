#include<bits/stdc++.h>
using namespace std;

#define N 1001
#define log 18
vector<int> graf[N];
int parent[N], preorder[N], postorder[N], ldx, lca[log][N], n;

int dfs(int v, int p) {
	parent[v]=p;
	lca[0][v]=p;
	preorder[v]=++ldx;
	for(int i=0; i<graf[v].size(); i++)
		if(graf[v][i]!=p)
			dfs(graf[v][i],v);
	postorder[v]=++ldx;
}

bool przodek(int v, int u) { //czy v jest przodkiem u
	if(preorder[v]<preorder[u] && postorder[v]>preorder[u]) return true;
	return false;
}

int getlca(int v, int u) {
	if(przodek(v,u)) return v;//to important
	if(przodek(u,v)) return u;
	for(int i=log-1; i>=0; i--) //wystarczy skakac potegami 2
		if(!przodek(lca[i][v],u)) 
			v = lca[i][v];
	return lca[0][v];
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1; i<=n-1; i++)
	{
		int v, u;
		cin>>v>>u;
		graf[v].push_back(u);
		graf[u].push_back(v);
	}
	dfs(1,1);
	for(int i = 1; i < log; i++)
		for(int v=1; v<=n; v++)
			lca[i][v]=lca[i-1][lca[i-1][v]];
	//od teraz getlca(v,u) zwraca wierzcholek, ktory jest lca dla v,u
	
	int a,b;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>a>>b;
		cout<<getlca(a,b);
	}
	
	return 0;
}
