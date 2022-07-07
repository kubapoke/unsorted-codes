#include<iostream>
using namespace std;

int main()
{
	//wczytanie tablic z cz¹stkami i zapytaniami
	
	int n, q;
	
	cin>>n;
	int cz[n];
	
	for(int i=0; i<n; i++)
	{
		cin>>cz[i];
	}
	
	cin>>q;
	int zap[q];
	int odp[q];
	
	for(int i=0; i<q; i++)
	{
		cin>>zap[i];
		odp[i]=0;
	}
	
	//szukanie odpowiedzi
	
	int licz=0;				//zapytania
	int sr=cz[n/2];			//œrodek
	
	while(licz!=q)
	{
		sr=cz[n/2];
		
		while(sr!=zap[licz])
		{
			if(sr>zap[licz])
			
			
		}
		
		licz++;
	}
	
	return 0;
}
