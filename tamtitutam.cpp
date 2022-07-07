#include<iostream>
#include<algorithm>
using namespace std;

int roz[500001];
int odl[500001];
int sum[500001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, a, b;
	
	cin>>n;
	
	for(int i=1; i<=n; i++)
	{
		roz[i]=0;
		odl[i]=0;
		sum[i]=0;
	}
	
	for(int i=1; i<=n-1; i++)
	{
		cin>>a>>b;
		
		if(a<b)
		{
			odl[b]=odl[a]+1;
			roz[b]=roz[a];
		}
		else
		{
			odl[a]=odl[b]+1;
			roz[a]=roz[b];
		}
		
		roz[a]++;
		roz[b]++;
	}
	
	roz[1]-=1;
	
	for(int i=2; i<=n; i++)
	{
		if(roz[i]>2)
		roz[i]-=2;
		else
		roz[i]=0;
	}
	
	for(int i=1; i<=n; i++)
	{
		if(roz[i]<0)
		sum[i]=odl[i];
		else
		sum[i]=roz[i]*2+odl[i];
	}
	
	sort(sum, sum+500001);
	
	cout<<sum[500000];
}
