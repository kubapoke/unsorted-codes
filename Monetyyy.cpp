#include<iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, x;
	
	cin>>n;
	
	int tab[n];
	
	for(int i=0; i<n; i++)
	{
		cin>>tab[i];
	}
	
	sort(tab, tab+n);
	
	if(tab[n-1]==0)
	{
		cout<<"0";
		return 0;
	}
	
	for(int i=0; i<n; i++)
	{
		if(tab[i]==1)
		if(i*2>n)
		{
			cout<<n-i;
			return 0;
			
		}	
		else
		{
			cout<<i;
			return 0;	
		}
		
	}
		
	return 0;
}
