#include<iostream>
#include<cmath>
#include<math.h>
#include<iomanip>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	register int a, b, z, dol, gora;
	
	cin>>a;
	
	int tab[a];
	
	for(int i=0; i<a; i++)
	cin>>tab[a];
	
	register int p, k, s;
	
	cin>>b;
	
	for(int i=0; i<b; i++)
	{
		cin>>z;
		
		p=0;
		k=a-1;
		s=(p+k)/2;
		
		//szukanie do³u
		while(tab[s]!=z||tab[s-1]==z)
		{
			if(tab[s]>=z)
			{
				k=s-1;
				s=(p+k)/2;
			}
			else
			{
				p=s+1;
				s=(p+k)/2;
			}
			
			if(tab[s]>z&&tab[s-1]<z)
			{
				s=0;
				break;
			}
			if(tab[s]<z&&tab[s+1]>z)
			{
				s=0;
				break;
			
			}
		}
		
		dol=s;
		cout<<dol<<'\n';
		
		p=0;
		k=a-1;
		s=(p+k)/2;
		
		//szukanie góry
		while(tab[s]!=z||tab[s+1]==z)
		{
			if(tab[s]>z)
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
		cout<<gora<<'\n';
		
		cout<<gora-dol+1<<'\n';
}
	
	return 0;
}
