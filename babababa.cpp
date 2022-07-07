#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, x, w=0;
	
	cin>>n; 
	
	int tab[1000001];
	
	for(int i=0; i<=1000001; i++)
	tab[i]=0;
	
	for(int i=0; i<n; i++)
	{
		cin>>x;
		
		tab[x]++;	
	}
		
	for(int i=0; i<=1000001; i++)
	{
		if(tab[i]>=3)
		w+=(tab[i]*tab[i]-1*tab[i]-2)/6;
	}
	
	cout<<w;
	
	return 0;
}
