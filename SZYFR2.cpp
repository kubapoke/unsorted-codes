#include<bits/stdc++.h>
using namespace std;

int n, arr[40], sum;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	cin>>arr[i];
	
	cin>>sum;
	
	if(n<=20)
	{
		for(int i=0; i<(1<<n); i++)
		{
			int s=0;
			for(int j=0; j<n; j++)
			{
				if(i & (1<<j))
				s+=arr[j];
			}
			if(s==sum)
			{
				for(int j=0; j<n; j++)
				{
					if(i & (1<<j))
					cout<<1;
					else
					cout<<0;
				}
				return 0;
			}
		}
	}
	else
	{
		unordered_map<int,long long> m;
		vector<int> v1, v2;
		
		for(int i=0; i<n; i++)
		{
			if(i<n/2)
			v1.push_back(arr[i]);
			else
			v2.push_back(arr[i]);
		}
		for(int i=0; i<(1<<v2.size()); i++)
		{
			int s=0;
			for(int j=0; j<v2.size(); j++)
			{
				if(i & (1<<j))
				s+=v2[j];
			}
			m[s]=i;
		}	
		for(int i=0; i<(1<<v1.size()); i++)
		{
			int s=0;
			for(int j=0; j<v1.size(); j++)
			{
				if(i & (1<<j))
				s+=v1[j];
			}
			if(m.count(sum-s)>0)
			{
				for(int j=0; j<v1.size(); j++)
				{
					if(i & (1<<j))
					cout<<1;
					else
					cout<<0;
				}
				
				i=m[sum-s];
				
				for(int j=0; j<v2.size(); j++)
				{
					if(i & (1<<j))
					cout<<1;
					else
					cout<<0;
				}
				
				return 0;
			}
		}
	}
}
