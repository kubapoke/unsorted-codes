#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	register int d, n, l, x, max=0, w=0;
	
	cin>>d>>n;
	
	int tab[d];
	
	for(int i=0; i<d; i++)
	tab[i]=0;
	
	for(int i=0; i<n; i++)
	{
		cin>>l>>x;
		
		max=0;
		
		for(int j=x; j<x+l; j++)
		if(tab[j]>max)
		max=tab[j];
		
		max++;
		
		if(max>w)
		w=max;
		
		for(int j=x; j<x+l; j++)
		tab[j]=max;
	}
	
	cout<<w;
}
