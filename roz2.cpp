#include<bits/stdc++.h>
#define NTREE 262144
using namespace std;

map<int,int> tree[NTREE*2], etree[NTREE*2];
map<int,int> check, echeck;
map<int,int>::iterator it;
char c;
int n, q, x, l, r, p, tim;

void update1(int v, int l, int r)
{
	l+=NTREE; r+=NTREE;
	
	if(l==r)
	{
		tree[l][v]=tim;
		return;
	}
	
	tree[l][v]=tim;
	tree[r][v]=tim;
	
	while(r-l>1)
	{
		if(l%2==0) tree[l+1][v]=tim;
		if(r%2==1) tree[r-1][v]=tim;
		l/=2;
		r/=2;
	}
}

void update2(int v, int l, int r)
{
	l+=NTREE; r+=NTREE;
	
	if(l==r)
	{
		etree[l][v]=tim;
		return;
	}
	
	etree[l][v]=tim;
	etree[r][v]=tim;
	
	while(r-l>1)
	{
		if(l%2==0) etree[l+1][v]=tim;
		if(r%2==1) etree[r-1][v]=tim;
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
		for(it=tree[pos].begin(); it!=tree[pos].end(); ++it)
		{
			check[it->first]=max(check[it->first],tree[pos][it->first]);
		}
		for(it=etree[pos].begin(); it!=etree[pos].end(); ++it)
		{
			echeck[it->first]=max(echeck[it->first],etree[pos][it->first]);
		}
		pos/=2;
	}
	
	for(it=check.begin(); it!=check.end(); ++it)
	{
		//cout<<check[it->first]<<"  "<<echeck[it->first]<<"   ";
		if(check[it->first]>echeck[it->first])
		sum++;
	}
	cout<<sum<<"\n";
	check.clear(); echeck.clear();
}

int main()
{
	ios_base::sync_with_stdio(0);
		
	cin>>n>>q;
	
	for(int i=1; i<=q; i++)
	{
		tim++;
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

