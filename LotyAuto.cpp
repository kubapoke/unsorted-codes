#include<bits/stdc++.h>
using namespace std;

int q;
vector<int> v;
int zaj[20];
bool b;

bool check_validity()
{
	for(int i=0; i<20; i++)
	zaj[i]=0;
	
	int x=0;
	
	for(int i=0; i<2*q; i++)
	{
		if(zaj[i]==0)
		{
			if(i+v[x]<2*q && zaj[i+v[x]]==0)
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
	
	
	
for(int n=1; n<=10; n++)
{
	cout<<n<<":\n";
	q=n;
	
	b=false;
	
	v.clear();
	for(int i=1; i<=n; i++)
	{
		v.push_back(i);
	}
	
	if(n==1)
	{
		cout<<"TAK\n1 1\n\n";
		continue;
	}
	if(n==10)
	{
		cout<<"NIE\n\n";
		continue;
	}
	
	while(next_permutation(v.begin(),v.end()))
	{
		if(check_validity())
		{
			cout<<"TAK\n";
			for(int i=0; i<2*n; i++)
			cout<<zaj[i]<<" ";
			cout<<"\n";
			
			for(int i=0; i<v.size(); i++)
			cout<<v[i]<<" ";
			cout<<"\n\n";
			
			b=true;
			break;
		}
	}
	
	if(!b)
	cout<<"NIE\n\n";
}
}
