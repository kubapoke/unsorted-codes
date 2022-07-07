#include<bits/stdc++.h>
using namespace std;

int n, p[1001], k[1001], ans, db[1001]; //p-stopieñ wyjœcia, k-stopieñ wejœcia //PRZY PRZECHODZENIU ZACZYNAMY OD NAJNI¯ESZEGO (ISTNIEJ¥CEGO) STOPNIA WEJŒCIA, ZAWSZE IDZIEMY DO NAJWIÊKSZEGO MO¯LIWEGO STOPNIA WEJŒCIA
vector<pair<int,int>> v, u;
//vector<int> graf[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	ans=2*n;
	
if(n<=10)
{	
	for(int i=0; i<n; i++)
	{
		int a, b;
		cin>>a>>b;
		v.push_back({a,b});
		u.push_back({a,b});
	}
	
	int pol=0;
	for(int i=1; i<v.size(); i++)
	{
		if(v[i].first==v[i-1].second)
		pol++;
	}
	
	if(n*2-pol<ans)
	{
		ans=n*2-pol;
		u=v;
	}
	
	while(next_permutation(v.begin(),v.end()))
	{
		pol=0;
		for(int i=1; i<v.size(); i++)
		{
			if(v[i].first==v[i-1].second)
			pol++;
		}
		
		if(n*2-pol<ans)
		{
			ans=n*2-pol;
			u=v;
		}
	}
	
	cout<<ans<<"\n";
	cout<<u[0].first<<" "<<u[0].second<<" ";
	
	for(int i=1; i<u.size(); i++)
	{
		if(u[i].first!=u[i-1].second)
		cout<<u[i].first<<" ";
		
		cout<<u[i].second<<" ";
	}
	
	return 0;
}
	
	for(int i=0; i<n; i++)
	{
		int a, b;
		cin>>a>>b;
		p[a]++; k[b]++;
		if(a==b)
		db[a]=1;
	}

	
	for(int i=1; i<=1000; i++)
	{
		ans-=min(p[i],k[i]);
		
		if(db[i])
		{
			if(p[i]==1 && k[i]==1)
			ans++;
		}
	}
	
	ans=max(ans,n+1);
	
	cout<<ans<<"\n";
	///
	
}
