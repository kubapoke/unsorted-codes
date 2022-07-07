#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n, w=0, sum=0;
	
	cin>>n;
	
	int tab[n];
	
	for(int i=0; i<n; i++)
	cin>>tab[i];
	
	sort(tab, tab+n);
	
	for(int i=0; i<n; i++)
	{	
		for(int j=i; j<n; j++)
		{
			sum+=tab[j];
			
			if(j==n-1)
			{
				cout<<n-i;
				return 0;
			}
			
			if(sum*2<tab[j+1])
			{
				i=j;
				break;	
			}
			
		}	
	}
	
}
