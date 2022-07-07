#include<iostream>
using namespace std;

int tab[1000001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	register int n, a, c, x=0;
	
	for(int i=0; i<1000001; i++)
	tab[i]=0;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>a;
		tab[a]++;
	}
	
	cin>>c;
	
	for(int i=0; i<c; i++)
	{
		cin>>a;
		for(int i=0; i<a; i++)
		x+=tab[i];
		cout<<x<<"\n";
		x=0;
	}
	
	return 0;
}
