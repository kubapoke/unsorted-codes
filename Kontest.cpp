#include<bits/stdc++.h>
using namespace std;

struct zgloszenie{
	long long a, s, p;
}z[1000000];

bool comp(zgloszenie a, zgloszenie b)
{
	if(a.s!=b.s)
	return(a.s<b.s);
	
	return(a.a<b.a);
}

long long n, m, t, cmax, ptime, cwin;
map<int,pair<long long,long long>> M; // nr zawodnika (nie bêdzie ich wiêcej ni¿ 1e6) -> {obecna iloœæ punktów, czas wygranej}
queue<pair<int, int>> ocz;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m>>t;
	
	for(int i=0; i<m; i++)
	{
		int a, s, p;
		cin>>a>>s>>p;
		zgloszenie Z;
		Z.a=a; Z.s=s; Z.p=p;
		z[i]=Z;
	}
	
	sort(z,z+m,comp);
	
	for(int i=0; i<m; i++)
	{
		int a, s, p;
		a=z[i].a; //numer zawodnika
		s=z[i].s; //czas zg³oszenia
		p=z[i].p; //punkty za zg³oszenie
		
		pair<long long, long long> x=M[a];
		
		x.first+=p;
		
		if(x.first>cmax)
		{
			if(cwin)
			{
				pair<long long, long long> y=M[cwin];
				y.second+=(s-ptime);
				M[cwin]=y;
			}
			
			cwin=a;
			cmax=x.first;
			ptime=s;
			
			M[a]=x;
			
			while(ocz.size())
			{
				pair<long long, long long> y=M[ocz.front().first];
				y.second+=(s-ocz.front().second);
				M[ocz.front().first]=y;
				ocz.pop();
			}
		}
		else if(x.first==cmax)
		{
			ocz.push({a,s});
		}
	}
	
	pair<long long, long long> x=M[cwin];
	x.second+=(t-ptime);
	M[cwin]=x;
	
	while(ocz.size())
	{
		pair<long long, long long> y=M[ocz.front().first];
		y.second+=(t-ocz.front().second);
		M[ocz.front().first]=y;
		ocz.pop();
	}
	
	cmax=0;
	int ans;
	
	for(auto it: M)
	{
		//cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<"\n";
		
		if(it.second.second>cmax)
		{
			cmax=it.second.second;
			ans=it.first;
		}
	}
	
	cout<<ans;
}
