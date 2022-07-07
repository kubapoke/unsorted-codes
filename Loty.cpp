#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
int zaj[20];

bool czypot(int c)
{
	if(c<3)
	return false;
	
	while(c>1)
	{
		if(c%2)
		return false;
		c/=2;
	}
	
	return true;
}

bool check_validity()
{
	for(int i=0; i<20; i++)
	zaj[i]=0;
	
	int x=0;
	
	for(int i=0; i<2*n; i++)
	{
		if(zaj[i]==0)
		{
			if(i+v[x]<2*n && zaj[i+v[x]]==0)
			{
				zaj[i]=v[x];
				zaj[i+v[x]]=v[x];
				x++;
				
				if(x==v.size())
				return true;
			}
			else
			return false;
		}
	}
	
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	for(int i=1; i<=n; i++)
	{
		v.push_back(i);
	}
	
if(n<=10)
{
	if(n==1)
	{
		cout<<"TAK\n1 1";
		return 0;
	}
	if(n==10)
	{
		cout<<"NIE";
		return 0;
	}
	
	while(next_permutation(v.begin(),v.end()))
	{
		if(check_validity())
		{
			cout<<"TAK\n";
			for(int i=0; i<2*n; i++)
			cout<<zaj[i]<<" ";
			
			return 0;
		}
	}
	
	cout<<"NIE";
	
	return 0;
}
	
	if((n%2==0 && czypot(n)) || (n%2==1 && czypot(n-1)))
	{
		cout<<"TAK\n";
		for(int i=0; i<v.size(); i++)
		cout<<v[i]<<" "<<v[i]<<" ";
	}
	else
	cout<<"NIE";
	
}
