#include<bits/stdc++.h>
using namespace std;

#define NTREE 1048576
int tree[NTREE*2], Q, A, B;

void update(int pos, int val)
{
	pos+=NTREE;
	while(pos)
	{
		tree[pos]+=val;
		pos/=2;
	}
}

int query(int l, int r)
{
	l+=NTREE; r+=NTREE;
	int sum=0;
	
	if(l==r)
	{
		return tree[l];
	}
	
	sum+=tree[l]+tree[r];
	
	while(r-l>1)
	{
		if(l%2==0) sum+=tree[l+1];
		if(r%2==1) sum+=tree[r-1];
		l/=2;
		r/=2;
	}	
	
	return sum;
}

long long kwad[1001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	for(int i=0; i<=1000; i++)
	{
		//cout<<i<<"\n";
		kwad[i]=pow(i,2);
		//cout<<i*i<<"\n";
	}
	
	
	for(int i=0; i<=1000; i++)
	{	
		if(tree[kwad[i]+NTREE]==0)
		update(kwad[i],1);
		//cout<<kwad[i]<<"\n";
		for(int j=0; j<=1000; j++)
		{
			if(kwad[i]+kwad[j]>1000000)
			break;
			if(tree[kwad[i]+kwad[j]+NTREE]==0)
			update(kwad[i]+kwad[j],1);
			//cout<<kwad[i]+kwad[j]<<"\n";
		}
	}
	
	cin>>Q;
	
	for(int i=1; i<=Q; i++)
	{
		cin>>A>>B;
		
		cout<<query(A,B)<<"\n";
	}
}
