#include<iostream>
#include<algorithm>
#include <cstdlib>
using namespace std;

int search(int min, int i)
{
	
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	register int n, w=30001, wt=0, min;
	
	cin>>n;
	
	int tab[n];
	
	for(int i=0; i<n; i++)
	cin>>tab[i];
	
	sort(tab, tab+n);
	
	for(int i=n-1; i>=2; i--)
	{
		if(n-1-i>w)
		break;
		
		wt=0;
		min=tab[i]/2+1;
		
		register int p=0, k=i, s=i/2;
		
		while(tab[s]<min||tab[s-1]>=min)
		{
			if(tab[s]>=min)
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
		
		wt=n-1-i+s;
		
		if(tab[i]%2==0&&tab[s-1]==tab[i]/2)
		wt--;
		
		if(wt<w)
		w=wt;
	}
	
	cout<<n-w;
	
	return 0;
}
