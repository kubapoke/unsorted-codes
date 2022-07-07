#include<bits/stdc++.h>
using namespace std;

int n, p[1000001], k[1000001], x[1000001];
long long parz;

long long ilemn(int A)
{
	long long W=0;
	
	for(int i=1; i<=n; i++)
	{
		if(A>=p[i])
		W+=1+(min(A,k[i])-p[i])/x[i];
	}
	
	return W;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	for(int i=1; i<=n; i++)
	{
		cin>>p[i]>>k[i]>>x[i];
		
		parz+=1+(k[i]-p[i])/x[i];
	}
	
	if(parz%2==0)
	{
		cout<<"NIE";
		return 0;
	}
	
	int pocz=1, kon=1e9, s;
	s=(pocz+kon)/2;
	
	while(pocz!=kon)
	{
		if(ilemn(s)%2==0)
		pocz=s+1;
		else
		kon=s;
		
		s=(pocz+kon)/2;
	}
	
	cout<<pocz<<" ";
	int odp=0;
	
	for(int i=1; i<=n; i++)
	{
		if(pocz>=p[i] && pocz<=k[i])
		{
			if((pocz-p[i])%x[i]==0)
			odp++;
		}
	}
	
	cout<<odp;
}
