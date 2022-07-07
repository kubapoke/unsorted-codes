#include<bits/stdc++.h>
#define NTREE 262144
#define INF 1e18
using namespace std;

//3 3 1 1 1 1 1 1 1 1 1 2 0 1 0 1 1 1 5 2 0 0 0 1 3 1 1 0 5 1 1 1 1 1

struct budynek{
	int l, r, c;
}bud[NTREE];

long long T, n, l, r, c, pocz, kon, a, b, x;
long long tree[2*NTREE], wart[NTREE];
bool vis[NTREE];
set<int> czyvis;
set<int>::iterator it1, it2, it3;
queue<long long> Q;

long long query(long long pos)
{
	long long ans=INF;
	pos+=NTREE;
	while(pos) 
	{
		ans=min(ans,tree[pos]);
		pos/=2;
	}
	return ans;
}

void update(long long l, long long r, long long val)
{
	if(l>r) return;
	l+=NTREE;
	r+=NTREE;
	
	tree[l]=min(tree[l],val);
	tree[r]=min(tree[r],val);
	while(r-l>1)
	{
		if(l%2==0) tree[l+1]=min(tree[l+1],val);
		if(r%2==1) tree[r-1]=min(tree[r-1],val);
		l/=2; r/=2;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>T;
	
	for(long long i=0; i<2*NTREE; i++)
	tree[i]=INF;
	
	for(long long i=0; i<NTREE; i++)
	wart[i]=-1;
	
	for(long long i=0; i<NTREE; i++)
	czyvis.insert(i);
	
	for(int te=1; te<=T; te++)
	{
		cin>>n;
		
		kon=pocz+n-1;
		
		for(long long i=0; i<n; i++)
		cin>>bud[i+pocz].l;
		for(long long i=0; i<n; i++)
		cin>>bud[i+pocz].r;
		for(long long i=0; i<n; i++)
		cin>>bud[i+pocz].c;
		
		update(pocz,pocz,0);
		
		Q.push(pocz);
		vis[pocz]=true;
		wart[pocz]=0;
		
		while(!Q.empty())
		{
			a=Q.front()-bud[Q.front()].l;
			b=Q.front()-bud[Q.front()].r;
			
			if(a>=pocz)
			{
				b=max(b,pocz);
				update(b,a,wart[Q.front()]+bud[Q.front()].c);
				
				it1=czyvis.lower_bound(b);
				for(it1; *it1<=a; it1++)
				{
					czyvis.erase(x);
					wart[*it1]=query(*it1);
					Q.push(*it1);
					x=*it1;
				}
				czyvis.erase(x);
				
			}
			
			
			a=Q.front()+bud[Q.front()].l;
			b=Q.front()+bud[Q.front()].r;
			
			if(a<=kon)
			{
				b=min(b,kon);
				update(a,b,wart[Q.front()]+bud[Q.front()].c);
				
				it1=czyvis.lower_bound(a);
				for(it1; *it1<=b; it1++)
				{
					czyvis.erase(x);
					wart[*it1]=query(*it1);
					Q.push(*it1);
					x=*it1;
				}	
				czyvis.erase(x);
				
			}
			
			Q.pop();
		}
		
		for(int i=pocz; i<=kon; i++)
		cout<<wart[i]<<" ";
		cout<<"\n";
		
		pocz+=n;
	}
	
	
}
