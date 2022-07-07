#include<iostream>
#include<algorithm>
#include <cstdlib>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	register int n, w=30001;
	
	cin>>n;
	
	int tab[n];
	
	for(int i=0; i<n; i++)
	cin>>tab[i];
	
	sort(tab, tab+n);
	
	/*
	void qsort(
	void tab,
	size_t num n,
	size_t width 12,
	int( * compare )( const void *, const void * )
	);
	*/
	
	for(int i=0; i<n-2; i++)
	{
		if(i>=w)
		break;
		
		if(tab[i+1]>tab[i]*2)
		continue;
		
		for(int j=n-1; j>i+1; j--)
		if(tab[i]+tab[i+1]>tab[j])
		{
			if(i+n-1-j<w)
			{
				w=i+n-1-j;
			}
			break;
		}	
	}
	
	cout<<n-w;
	
	return 0;
}
