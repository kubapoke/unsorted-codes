#include<iostream>
using namespace std;

int tab[500000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, q, a, b, c, x;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>tab[i];
	}
	
	cin>>q;
	
	for(int i=0; i<q; i++)
	{
		cin>>x;
		
		if(x==1)
		{
			cin>>a>>b;
			tab[a-1]=b;
		}
		else if(x==2)
		{
			cin>>a>>b>>c;
			for(int j=0; j<n; j++)
			if(tab[j]>=a && tab[j]<=b)
			tab[j]=c;	
		}
		else
		{
			cin>>a;
			cout<<tab[a-1]<<'\n';
		}
	}
			
}
