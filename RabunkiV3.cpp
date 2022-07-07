#include<bits/stdc++.h>
using namespace std;

int n;
long long ans;
int a[500001], b[500001];
stack<int> s;
vector<int> odp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	for(int i=1; i<=n; i++)
	cin>>a[i];
	for(int i=1; i<=n; i++)
	{
		cin>>b[i];
		ans+=abs(a[i]-b[i]);
	}
	
	for(int i=1; i<=n; i++)
	{
		if(a[i]>b[i])
		{
			while(!s.empty())
			{
				if(abs(a[s.top()]-b[i])<=abs(a[i]-b[i]))
				{
					odp.push_back(s.top());
					s.pop();
				}
				else
				break;
			}
			odp.push_back(i);
		}
		else
		s.push(i);
	}
	
	while(!s.empty())
	{
		odp.push_back(s.top());
		s.pop();
	}
	
	cout<<ans<<"\n";
	for(auto it: odp)
	cout<<it<<" ";
}
