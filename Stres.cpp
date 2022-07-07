#include<iostream>
using namespace std;

int main()
{
	long long k, s=0, w=0;
	
	cin>>k;
	
	int tab[k];
	
	for(int i=0; i<k; i++)
	{
		cin>>tab[i];
	}
	
	for(int i=0; i<k-1; i++)
	{
		for(int j=i+1; j<k; j++)
		{
			s=s+tab[j-1];
			
			if(s==tab[j])
			w++;				
		}
		s=0;
	}
	
	cout<<w;
	
	return 0;
}
