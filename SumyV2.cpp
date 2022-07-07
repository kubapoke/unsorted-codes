#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v;
multiset<int> liczby;
multiset<int>::iterator it;

int n, ans, p;
long long mn;

int odp(int n)
{
	mn=2;
	
	while(mn<=n)
	mn*=2;
	
	return mn-n;
}

bool comp(pair<int,int> a, pair<int,int> b)
{
	if(a.second!=b.second)
	return a.second<b.second;
	
	return a.first<b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		int a;
		cin>>a;
		v.push_back({a,odp(a)});
		liczby.insert(a);
	}
	
	sort(v.begin(), v.end(), comp);
	
	for(int i=v.size()-1; i>=0; i--)
	{
		if(v[i].first!=v[i].second && liczby.find(v[i].first)!=liczby.end() && liczby.find(v[i].second)!=liczby.end())
		{
			ans++;
			liczby.erase(liczby.find(v[i].first));
			liczby.erase(liczby.find(v[i].second));
			cout<<v[i].first<<" "<<v[i].second<<"\n";
		}
	}
	
	mn=1;
	
	for(it=liczby.begin(); it!=liczby.end(); it++)
	{
		while(mn<*it)
		mn*=2;
		
		if(it!=liczby.begin())
		{
			if(p==*it && mn==*it)
			{
				cout<<p<<" "<<p<<"\n";
				ans++;
				it++;
			}
		}
		p=*it;
	}
	
	cout<<ans;
	
}
