#include<bits/stdc++.h>
using namespace std;

int N, X, Y, A, B, cn;
stack<int> s;

#define NTREE 1048576 
int tree[NTREE*2];

void update(int val, int l, int r)
{
	l+=NTREE; r+=NTREE;
	
	if(l==r)
	{
		tree[l]+=val;
		return;
	}
	
	tree[l]+=val;
	tree[r]+=val;
	
	while(r-l>1)
	{
		if(l%2==0) tree[l+1]+=val;
		if(r%2==1) tree[r-1]+=val;
		l/=2;
		r/=2;
	}	
}

int query(int pos)
{
	pos+=NTREE;
	int sum=0;
	while(pos)
	{
		sum+=tree[pos];
		pos/=2;
	}
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>N>>X>>Y;
	
	for(int i=0; i<N; i++)
	{
		cin>>A>>B;
		update(1,A,B);
	}
	
	if(X<Y)
	for(int i=X; i<=Y; i++)
	{
		if(query(i)==0)
		{
			cn++;
			s.push(i);
		}
	}
	else
	for(int i=X; i>=Y; i--)
	{
		if(query(i)==0)
		{
			cn++;
			s.push(i);
		}	
	}
	
	cout<<cn<<"\n";
	
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	
}
