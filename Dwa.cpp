#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, x, l=1;
	bool czy=true;
	
	cin>>n;
	
	int tab[n];
	
	for(int i=0; i<n; i++)
	cin>>tab[i];
	
	sort(tab, tab+n);
	
	if(tab[0]==tab[n-1] || n<3)
	{
		cout<<"NIE";
		return 0;
	}
	
	for(int i=n-1; i>0; i--)
	{
		l=1;
		while((tab[i-1])/l!=0)
		{
			l*=10;
		}
		
		if(tab[i]/l==0 && tab[i]!=tab[i-1])
		{
			x=tab[i];
			tab[i]=tab[i-1];
			tab[i-1]=x;
			
			czy=false;
			
			break;
		}
	}
	
	
	if(czy==true)
	{
		x=tab[n-1];
		tab[n-1]=tab[n-2];
		tab[n-2]=x;		
	}
	
	for(int i=0; i<n; i++)
	cout<<tab[i]<<" ";
}
