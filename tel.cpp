#include<bits/stdc++.h>
#define NTREE 524288
using namespace std;

struct ST{
	int x,l,r,s,a;
}maszt[300001];

int n, m;
long long tree[NTREE*2], lazyA[NTREE*2], lazyB[NTREE*2];
char c;

long long ciag(int p, int k, int a, int s)
{
	return (1ll*2*s+(1ll*k-p)*a)*(1ll*k-p+1)/2;
}

void update(int v, int start, int end, int l, int r, int a, int b)
{
	int mid=(start+end)/2;
	
	if(lazyA[v]!=0||lazyB[v]!=0)
	{
		tree[v]+=ciag(start, end, lazyA[v], lazyB[v]);
		if(start!=end)
		{
			lazyA[v*2]+=lazyA[v];
			lazyA[v*2+1]+=lazyA[v];
			lazyB[v*2]+=lazyB[v];
			lazyB[v*2+1]+=lazyB[v]+(mid+1-start)*lazyA[v];
		}
		lazyA[v]=0; lazyB[v]=0;
	}
	
	if(start>r||end<l||start>end)
	return;
	
	if(start>=l&&end<=r)
	{
		b+=(start-l)*a;
		tree[v]+=ciag(start, end, a, b);
		if(start!=end)
		{
			lazyA[v*2]+=a;
			lazyA[v*2+1]+=a;
			lazyB[v*2]+=b;
			lazyB[v*2+1]+=b+(mid+1-start)*a;
		}
		return;
	}
	
	update(v*2, start, mid, l, r, a, b);
	update(v*2+1, mid+1, end, l, r, a, b);
	tree[v]=tree[v*2]+tree[v*2+1];
}

long long query(int v, int start, int end, int l, int r)
{
	int mid=(start+end)/2;
	
	if(start>r||end<l||start>end)
	return 0;
	
	if(lazyA[v]!=0||lazyB[v]!=0)
	{
		tree[v]+=ciag(start, end, lazyA[v], lazyB[v]);
		if(start!=end)
		{
			lazyA[v*2]+=lazyA[v];
			lazyA[v*2+1]+=lazyA[v];
			lazyB[v*2]+=lazyB[v];
			lazyB[v*2+1]+=lazyB[v]+(mid+1-start)*lazyA[v];
		}
		lazyA[v]=0; lazyB[v]=0;
	}
	
	if(start>=l&&end<=r)
	return tree[v];
	
	long long q1=query(v*2, start, mid, l, r);
	long long q2=query(v*2+1, mid+1, end, l, r);
	return q1+q2;
}



int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>n>>m;
	
	for(int i=0; i<m; i++)
	{
		cin>>c;
		
		if(c=='P')
		{
			int x, s, a;
			cin>>x>>s>>a;
			int d=s/a;
			int l=x-d, r=x+d;
			l=max(l,1); r=min(r,n);
			update(1, 0, NTREE-1, x, x, 0, s);
			if(l<=x-1) update(1, 0, NTREE-1, l, x-1, a, s-a*(x-l));
			if(r>=x+1) update(1, 0, NTREE-1, x+1, r, -a, s-a);
			maszt[x].l=l; maszt[x].r=r; maszt[x].x=x; maszt[x].s=s; maszt[x].a=a;
		}
		else if(c=='U')
		{
			int x;
			cin>>x;
			int l=maszt[x].l, r=maszt[x].r, s=maszt[x].s, a=maszt[x].a;
			update(1, 0, NTREE-1, x, x, 0, -s);
			if(l<=x-1) update(1, 0, NTREE-1, l, x-1, -a, -s+a*(x-l));
			if(r>=x+1) update(1, 0, NTREE-1, x+1, r, a, -s+a);
			maszt[x].l=0; maszt[x].r=0; maszt[x].x=0; maszt[x].s=0; maszt[x].a=0;
		}
		else
		{
			int p, k;
			cin>>p>>k;
			cout<<query(1, 0, NTREE-1, p, k)/(k-p+1)<<"\n";
		}
	}
	
}
