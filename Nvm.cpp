#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	register int k, mn, w;
	
	cin>>k;
	
	int tab[k+2];
	
	tab[k+1]=0;
	
	for(int i=0; i<k+1; i++)
	{
		cin>>tab[i];
	}
	
	for(int i=0; i<k+1; i++)
	{
		while(tab[i]>1)
		{
			tab[i]-=2;
			tab[i+1]+=1;
		}
	}
	
	
}
