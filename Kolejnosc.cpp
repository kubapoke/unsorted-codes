#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fib[87];
set<ll> fibset;
map<ll, map<ll,ll> > roz;
map<ll, map<ll,ll> >::iterator it;
map<ll,ll>::iterator x;
map<ll,vector<ll> > factors;
map<ll,vector<ll> >::iterator v;
vector<ll> primefib; 
set<ll> unique_fib;
set<ll>::iterator s;


void rozklad(ll n)
{
	ll f=n;
	/*
	while(n%2==0)
	{
		roz[f][2]++;
		n/=2;
	}
	*/
	for(ll i=2; (ll) i*i<=n; i++)
	while(n%i==0)
	{
		roz[f][i]++;
		n/=i;
	}
	
	if(n>1)
	roz[f][n]++;
	
	if(roz[f].size()==1 && (*(roz[f].begin())).second==1)
	primefib.push_back(n);
}


int main()
{
	fib[1]=1; fib[2]=2;
	fibset.insert(1); fibset.insert(2);
	
	for(int i=3; i<87; i++)
	fib[i]=fib[i-1]+fib[i-2];
	
	for(int i=2; i<87; i++)
	rozklad(fib[i]);
	
	cout<<"prime Fibonacci numbers:\n";
	for(int i=0; i<primefib.size(); i++)
	cout<<primefib[i]<<" ";
	cout<<"\n\n";
	
	cout<<"factorization:\n";
	for(it=roz.begin(); it!=roz.end(); it++)
	{
		cout<<it->first<<": ";
		for(x=it->second.begin(); x!=it->second.end(); x++)
		{
			cout<<x->first<<"^"<<x->second<<"  ";
			factors[x->first].push_back(it->first);
		}
		cout<<"\n";
	}
	cout<<"\n\n";
	
	cout<<"factors:\n";
	for(v=factors.begin(); v!=factors.end(); v++)
	{
		cout<<v->first<<": ";
		if(v->second.size()==1)
		unique_fib.insert(v->second[0]);
		for(int i=0; i<v->second.size(); i++)
		cout<<v->second[i]<<" ";
		cout<<"\n";
	}
	cout<<"\n\n";
	
	cout<<"unique factors:\n";
	for(s=unique_fib.begin(); s!=unique_fib.end(); s++)
	cout<<*s<<"\n";
	cout<<"\n\n";
}
