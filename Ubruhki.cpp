#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	register int n, w=30001, max, min, c=0;
	register bool czy1=false, czy2=false;
	
	cin>>n;
	
	int tab[n];
	
	for(int i=0; i<n; i++)
	cin>>tab[i];
	
	sort(tab, tab+n);
	
	
	for(int i=n-1; i>1; i--)
	{
		if(n-1-i>=w)
		break;
		
		max=tab[i];
		min=(max/2)+1;
		
		c=0;
		
		for(int j=0; tab[j]<min; j++)
		{
			c++;
		}
		if(c+n-1-i<w)
		w=c+n-1-i;	
	}
	
	
	cout<<n-w;
	
	return 0;
}
