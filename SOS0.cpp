#include<bits/stdc++.h>
using namespace std;

long long n, a[100001], b[100001], sval, ans;

long long check(int i)
{
	long long N=abs(b[i]), M;

	if(sval>=0)
	{
		long long x=sval/N;
		long long r=sval-x;
		
		if(r*2<=N)
		M=x;
		else
		M=x+1;
		
		if(sval*b[i]>=0)
		M=min(M,a[i]);
		
		return sval-N*M;
	}
	else
	{
		long long x=sval/N;
		long long r=sval+x;
		
		if(r*2<=N)
		M=x;
		else
		M=x+1;
		
		if(sval*b[i]>=0)
		M=min(M,a[i]);
		
		return sval+N*M;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	for(int i=1; i<=n; i++)
	cin>>a[i];
	
	for(int i=1; i<=n; i++)
	{
		cin>>b[i];
		sval+=a[i]*b[i];
	}
	
	ans=sval;
	
	for(int i=1; i<=n; i++)
	if(abs(ans)>abs(check(i)))
	ans=check(i);
	
	cout<<abs(ans);
}
