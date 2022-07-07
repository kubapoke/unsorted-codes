#include<bits/stdc++.h> //find and union
using namespace std;

#define N 1001 //max iloœæ elementów

int n, parent[N], ranga[N];

void init()
{
	for(int i=1; i<=n; i++)
	parent[i]=i;
}

int find(int v)
{
	if(v==parent[v])
	return v;
	return parent[v]=find(parent[v]);
}

void union_sets(int v, int u)
{
	int a=find(v), b=find(u);
	if(a!=b)
	{
		if(ranga[a]>ranga[b])
		swap(a,b);
		
		parent[a]=b;
		if(ranga[a]==ranga[b])
		ranga[b]++;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	init();
	return 0;
}
