#include<bits/stdc++.h>
#define NTREE 1048576
using namespace std;
vector<int> pos[NTREE];
int n, m, j, tree[NTREE*2], film[NTREE], wart[NTREE], ile[NTREE], ans;

/*
8 11
1 2 3 4 5 6 7 8
5 6 2 5 2 8 5 5 4 4 2
*/

void add(int p, int v)
{
	p+=NTREE-1;
	
	while(p)
	{
		tree[p]+=v;
		p/=2;
	}
}

int check(int p, int q)
{
	int s=0;
	
	p+=NTREE-1; q+=NTREE-1;
	
	if(p==q)
	{
		s+=tree[p];
		return s;
	}
	
	s=max(tree[p],tree[q]);
	
	while(q-p>1)
	{
		if(p%2==0) s=max(s,tree[p+1]);
		if(q%2==1) s=max(s,tree[q-1]);
		q/=2;
		p/=2;
	}
	
	return s;
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>n>>m;
	
	for(int i=1; i<NTREE; i++)
	pos[i].push_back(1);
	
	for(int i=1; i<=n; i++)
	cin>>wart[i];
	
	for(int i=1; i<=m; i++)
	{
		cin>>film[i];
		ile[film[i]]++;		
		
		pos[film[i]].push_back(i);
		
		if(ile[film[i]]==1)
		add(i,wart[film[i]]);
		else if(ile[film[i]]==2)
		add(i,-wart[film[i]]);
	}
	
	for(int i=NTREE; i<NTREE+m; i++)
	cout<<tree[i]<<" ";
	
	cout<<"\n\n"<<check(NTREE,NTREE*2-1);
	
	
	
	
	
}
