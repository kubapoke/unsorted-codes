#include<bits/stdc++.h>
using namespace std;

int n, maxx;

struct zapytanie{
	int p, k, x;
}z[1000000];

map<long long,long long> odw;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		zapytanie Z;
		cin>>Z.p>>Z.k>>Z.x;
		z[i]=Z;
		
		maxx=max(maxx,Z.x);
	}
	/*
	if(maxx == 1)
	{
		
		return 0;
	}
	*/
	for(int i=0; i<n; i++)
	{
		for(long long j=z[i].p; j<=z[i].k; j+=z[i].x)
		odw[j]++;
	}
	
	for(auto it:odw)
	{
		if(it.second%2!=0)
		{
			cout<<it.first<<" "<<it.second;
			return 0;
		}
	}
	
	cout<<"NIE";
}
