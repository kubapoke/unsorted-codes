#include<bits/stdc++.h>
#define NTREE 262144
using namespace std;

set<int> tree[NTREE*2];
char c;
int n, q, x, l, r, p;

void update1(int v, int l, int r)
{
	l+=NTREE; r+=NTREE;
	
	if(l==r)
	{
		tree[l].insert(v);
		return;
	}
	
	tree[l].insert(v);
	tree[r].insert(v);
	
	while(r-l>1)
	{
		if(l%2==0) tree[l+1].insert(v);
		if(r%2==1) tree[r-1].insert(v);
		l/=2;
		r/=2;
	}
}

void update2(int v, int l, int r)
{
	l+=NTREE; r+=NTREE;
	
	if(l==r)
	{
		tree[l].erase(v);
		return;
	}
	
	tree[l].erase(v);
	tree[r].erase(v);
	
	while(r-l>1)
	{
		if(l%2==0) tree[l+1].erase(v);
		if(r%2==1) tree[r-1].erase(v);
		l/=2;
		r/=2;
	}
}

void query(int pos)
{
	pos+=NTREE;
	int sum=0;
	while(pos)
	{
		sum+=tree[pos].size();
		pos/=2;
	}
	cout<<sum<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>n>>q;
	
	for(int i=1; i<=q; i++)
	{
		cin>>c;
		if(c=='+')
		{
			cin>>x>>l>>r;
			update1(x,l,r);
		}
		if(c=='-')
		{
			cin>>x>>l>>r;
			update2(x,l,r);
		}
		if(c=='?')
		{
			cin>>p;
			query(p);
		}
	}
}

