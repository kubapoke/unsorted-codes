#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	register int n, a;
	register bool czy=true;
	
	cin>>n;
	int tab[n];
	
	for(int i=0; i<n; i++)
	tab[i]=0;
	
	for(int i=0; i<n; i++)
	{
		cin>>a;
		if(a>0 && a<=n)
		tab[a-1]++;
	}
	
	for(int i=0; i<n; i++)
	{
		if(tab[i]!=1)
		{
			czy=false;
		}
	}
	
	if(czy==true)
	cout<<"TAK";
	if(czy==false)
	cout<<"NIE";
	
	return 0;
}
