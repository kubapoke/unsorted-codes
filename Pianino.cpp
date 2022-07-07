#include<iostream>
#include <iomanip>      
using namespace std;

int main()
{
	ios_base::sync_with_stdio;
	cin.tie(0);
	
	register int n, najw=-1, najm=1000000001, c=0;
	
	cin>>n;
	
	int tab[n];
	int klaw[24]={1,0,1,0,1,1,0,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1};
	
	register bool czy=true;
	
	for(int i=0; i<n; i++)
	{
		cin>>tab[i];
	
		if(tab[i]>najw)
		najw=tab[i];
		if(tab[i]<najm)
		najm=tab[i];
	}
	
	for(int i=najm; i>0; i--)
	{
		czy=true;
		
		for(int j=0; j<n; j++)
		{
			tab[j]--;
			while(tab[j]>23)
			{
				tab[j]-=24;
				c++;
			}
			if(klaw[tab[j]]==0)
			czy=false;
			while(c>0)
			{
				tab[j]+=24;
				c--;
			}
		}
		
		if(czy==true)
		{
			cout<<"TAK"<<'\n';
			for(int j=0; j<n; j++)
			cout<<tab[j]<<" ";
			return 0;
		}	
	}
	
	for(int j=0; j<n; j++)
	tab[j]+=najm;
	
	najw=23-najw;
	
	for(int i=najw; i>0; i--)
	{
		czy=true;
		
		for(int j=0; j<n; j++)
		{
			tab[j]++;
			while(tab[j]>23)
			{
				tab[j]-=24;
				c++;
			}
			if(klaw[tab[j]]==0)
			czy=false;
			while(c>0)
			{
				tab[j]+=24;
				c--;
			}
		}
		
		if(czy==true)
		{
			cout<<"TAK"<<'\n';
			for(int j=0; j<n; j++)
			cout<<tab[j]<<" ";
			return 0;
		}	
	}
	
	cout<<"NIE";
	
	return 0;
}
