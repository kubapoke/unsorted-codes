#include<bits/stdc++.h>
#define NTREE 524288
using namespace std;

int n, m;
long long treeleft[2*NTREE], lazyleft[2*NTREE], treeright[2*NTREE], lazyright[2*NTREE];

void updateleft(int v, int start, int end, int l, int r, int val)
{
	if(lazyleft[v]!=0)
	{
		treeleft[v]+=lazyleft[v];
		if(start!=end)
		{
			int nextdis=(end-start+1)/2;
			lazyleft[2*v]+=lazyleft[v]-(((1+(nextdis))*(nextdis))/2);
			lazyleft[2*v+1]+=lazyleft[v]+(((1+(nextdis))*(nextdis))/2);
		}
		lazyleft[v]=0;
	}
	
	if(start>r||end<l||start>end)
	return;
	
	if(start>=l&&end<=r)
	{
		long long f=val-(r-end);
		long long s=val-(r-start);
		int dis=(start-end)+1;
		int tval=((f+s)*dis)/2;
		
		treeleft[v]+=tval;
		
		if(start!=end)
		{
			int nextdis=(end-start+1)/2;
			lazyleft[2*v]+=tval-(((1+(nextdis))*(nextdis))/2);
			lazyleft[2*v+1]+=tval+(((1+(nextdis))*(nextdis))/2);
		}
	}
	
	int mid=(start+end)/2;
	updateleft(2*v,start,mid,l,r,val);
	updateleft(2*v+1,mid+1,end,l,r,val);
	treeleft[v]+=treeleft[v*2]+treeleft[v*2+1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	
	for(int i=0; i<m; i++)
	{
		
	}
}
