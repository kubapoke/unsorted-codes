#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	register int k, n, c;
	
	int tab[1001];
	tab[0]=0;
	tab[1]=0;
	
	for(int i=2; i<1000; i++)
	tab[i]=1;
	
	for(int i=2; i<1001; i++)
	{
		if(tab[i]==0)
		continue;
		
		c=i;
		
		while(c+i<1001)
		{
			c+=i;
			tab[c]=0;
		}
	}
	
	cin>>k;
	
	for(int i=0; i<k; i++)
	{
		cin>>n;
		
		c=2;
		
		if(n==0)
		{
			cout<<"0"<<'\n';
			continue;
		}
		if(n==1)
		{
			cout<<"1"<<'\n';
			continue;
		}
		
		while(n!=1)
		{
			if(n%c==0)
			{
				cout<<c;
				n/=c;
				if(n!=1)
				cout<<"*";
			}
			else
			{
				do
				{
					c++;
					if(c>1000)
					{
						cout<<n;
						break;
					}
				}
				while(tab[c]==0);
			}
			if(c>1000)
				{
					break;
				}	
		}
		
		cout<<'\n';
	}
	
}
