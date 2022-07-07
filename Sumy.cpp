#include<bits/stdc++.h>
using namespace std;

vector<int> v;
multiset<int> liczby;
multiset<int>::iterator it;

int n, ans, p;
long long mn=2;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		int a;
		cin>>a;
		v.push_back(a);
	}
	
	sort(v.begin(), v.end());
	
	for(auto i: v)
	{
		while(i>=mn)
		mn*=2;
		
		if(!liczby.empty())
		{
			if(liczby.find(mn-i)!=liczby.end() && mn-i!=i)
			{
				ans++;
				liczby.erase(liczby.find(mn-i));
				
				cout<<mn-i<<" "<<i<<"\n";
			}
			else
			{
				liczby.insert(i);
			}
		}
		else
		{
			liczby.insert(i);
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
