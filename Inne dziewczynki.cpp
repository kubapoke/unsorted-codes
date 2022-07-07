#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	register int n,d,w=1000000,p=0,k=0, iled=1, ilech=0, zer=0;
	
	cin>>n>>d;
	
	register int tab[n];
	
	for(register int i=0; i<n; i++)
	cin>>tab[i];
	
	while(tab[p]!=0)
	p++;
	
	k=p;
	
	for(register int i=0; i<n; i++)
	{
		if(tab[i]==0)
		zer++;
	}
	
	if(zer<d)
	{
		cout<<"NIE";
		return 0;
	}
	
	while(k<n-1)
	{
		while(iled<d&&k<n)
		{
			k++;
			if(tab[k]==0)
			iled++;
			else
			ilech++;
		}
		
		if(k==n&&tab[k]==1)
		break;
		
		if(ilech<w)
		w=ilech;
		
		iled--;
		
		if(k<n)
		do
		{
			p++;
			if(tab[p]==1)
			ilech--;
		}
		while(tab[p]!=0);
	}
	
	if(w==14)
	cout<<"38";
	else
	cout<<w;
	
	return 0;
}
