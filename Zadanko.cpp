#include<iostream>
#include<cmath>
#include<math.h>
#include<iomanip>
#include<algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	register int n, a, b, p, k, s, dol, gora, wyb;
	register bool pom=false;
	
	cin>>n;
	
	int tab[n];
	
	for(int i=0; i<n; i++)
	cin>>tab[i];
	
	sort(tab, tab+n);
	
	cin>>a;
	
	for(int i=0; i<a; i++)
	{
		cin>>b;
		
		p=0;
		k=n-1;
		s=(p+k)/2;
		
		while(tab[s]!=b||tab[s-1]==b)
		{
			if(tab[s]>=b)
			{
				k=s-1;
				s=(p+k)/2;
			}
			else
			{
				p=s+1;
				s=(p+k)/2;
			}
			
			if((tab[s]>b&&(tab[s-1]<b||s==0))||(tab[s]<b&&(tab[s+1]>b||s==n-1)))
			{
				pom=true;
				break;
			}
		}
		
		if(pom==true)
		{
			pom=false;
			cout<<"0"<<'\n';
			continue;
		}
		
		
		dol=s;
		
		p=dol;
		k=n-1;
		s=(p+k)/2;
		
		while(tab[s]!=b||tab[s+1]==b)
		{
			if(tab[s]>b)
			{
				k=s-1;
				s=(p+k)/2;
			}
			else
			{
				p=s+1;
				s=(p+k)/2;
			}
		}
		
		gora=s;
		
		cout<<gora-dol+1<<'\n';
	}
	
	
}
