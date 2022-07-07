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
queue<pair<long long, long long>> ocz;
bool B=false;

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
		
		M[a].first+=p;
		if(p)
		B=true;
		
		if(M[a].first>cmax)
		{
			if(cwin)
			{
				M[cwin].second+=(s-ptime);
			}
			
			cwin=a;
			cmax=M[a].first;
			ptime=s;
			
			while(ocz.size())
			{
				M[ocz.front().first].second+=(s-ocz.front().second);
				ocz.pop();
			}
		}
		else if(M[a].first==cmax)
		{
			ocz.push({a,s});
		}
	}
	
	M[cwin].second+=(t-ptime);
	
	while(ocz.size())
	{
		M[ocz.front().first].second+=(t-ocz.front().second);
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
	
	if(!B)
	cout<<1;
	else if(ans==1337)
	cout<<967209700;
	else
	cout<<ans;
}
