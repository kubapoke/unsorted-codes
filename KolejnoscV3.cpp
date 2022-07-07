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
set<ll>::reverse_iterator rs;
queue<ll> Q;


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
	fibset.insert(2);
	
	for(int i=3; i<87; i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
		fibset.insert(fib[i]);
	}
	for(int ob=1; ob; ob++)
	{
		roz.clear(); factors.clear(); primefib.clear(); unique_fib.clear();
		
		for(s=fibset.begin(); s!=fibset.end(); s++)
		rozklad(*s);
		
		/*
		cout<<"prime Fibonacci numbers:\n";
		for(int i=0; i<primefib.size(); i++)
		cout<<primefib[i]<<" ";
		cout<<"\n\n";
		*/
		
		//cout<<"factorization:\n";
		for(it=roz.begin(); it!=roz.end(); it++)
		{
			//cout<<it->first<<": ";
			for(x=it->second.begin(); x!=it->second.end(); x++)
			{
				//cout<<x->first<<"^"<<x->second<<"  ";
				factors[x->first].push_back(it->first);
			}
			//cout<<"\n";
		}
		//cout<<"\n\n";
		
		//cout<<"factors:\n";
		for(v=factors.begin(); v!=factors.end(); v++)
		{
			//cout<<v->first<<": ";
			if(v->second.size()==1)
			unique_fib.insert(v->second[0]);
			//for(int i=0; i<v->second.size(); i++)
			//cout<<v->second[i]<<" ";
			//cout<<"\n";
		}
		//cout<<"\n\n";
		
		//cout<<"unique factors:\n";
		if(unique_fib.size()==0)
		break;
		for(rs=unique_fib.rbegin(); rs!=unique_fib.rend(); rs++)
		{
			Q.push(*rs);
			s=lower_bound(fibset.begin(), fibset.end(), *rs);
			fibset.erase(s);
		}
		//cout<<*s<<"\n";
		//cout<<"\n\n";
		//cout<<"obieg "<<ob<<": ";
		while(Q.size())
		{
			cout<<Q.front()<<",";
			Q.pop();
		}
		//cout<<"\n";
	}
	
	//cout<<"pozostale: ";
	for(rs=fibset.rbegin(); rs!=fibset.rend(); rs++)
	cout<<*rs<<",";
}
