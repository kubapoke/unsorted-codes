#include<bits/stdc++.h>
using namespace std;

int n;
set<int> P, B;
vector<int> BW;
set<int>::iterator it;
long long ans;
vector<int> wynik;
priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> PQ;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		int a;
		cin>>a;
		P.insert(a);
	}
	for(int i=0; i<n; i++)
	{
		int a;
		cin>>a;
		B.insert(a);
		BW.push_back(a);
	}
	
	while(P.size())
	{
		for(it=B.begin(); it!=B.end(); it++)
		{
			long long a, b;
		
			if(P.lower_bound(*it)!=P.end())	
			a=*P.lower_bound(*it);
			
			PQ.push({a-*it,{a,*it}});
			
			if(P.lower_bound(*it)!=P.end())
			a=*prev(P.lower_bound(*it));
			
			PQ.push({*it-a,{a,*it}});
		}
		
		cout<<PQ.size();
		
		while(PQ.size())
		{
			if(P.find(PQ.top().second.first)!=P.end() && B.find(PQ.top().second.second)!=B.end())
			{
				ans+=PQ.top().first;
				P.erase(P.find(PQ.top().second.first)); B.erase(B.find(PQ.top().second.second));
			}
			
			PQ.pop();
		}
	}
	
	cout<<ans;
}
