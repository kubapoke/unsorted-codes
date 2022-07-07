#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio;
	cin.tie(0);
	
	register int n, min, w=0, count;
	bool czy=false;
	
	cin>>n;
	
	int tab[n];
	
	for(int i=0; i<n; i++)
	cin>>tab[i];
	
	sort(tab, tab+n);
	
	for(int i=n-1; i>1; i--)
	{
		if(n-(n-1-i)<w)
		break;
		
		min=tab[i]/2+1;
		
		count=0;
		for(int j=0; i<min; i++)
		{
			count++;
			if(tab[j]==min)
			czy=true;
		}
		
		if(n-count-(n-1-i)>w)
		w=n-count-(n-1-i);
	}
	
	if(czy==true && tab[n-1]%2==0)
	w++;
	
	cout<<w;
}
