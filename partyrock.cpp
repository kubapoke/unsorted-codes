#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, c=1, x=1;
	long long k;
	
	cin>>n>>k;
	
	char tab[n];
	
	for(int i=0; i<n; i++)	
	{
		if(c==1)
		tab[i]='a';
		else if(c==2)
		tab[i]='b';
		else if(c==3)
		tab[i]='c';
		
		if(c<3)
		c++;
		else
		c=1;
	}
	
	for(int i=1; i<k; i++)	
	{
		do
		{
			tab[n-x]++;
		}
		while(tab[n-x]==tab[n-x+1] || tab[n-x]==tab[n-x+2] || tab[n-x]==tab[n-x-1] || tab[n-x]==tab[n-x-2]);
		
		
		
		while(tab[n-x]>122)
		{
			if((x-n)==0)
			{
				cout<<"NIE";
				return 0;
			}
			
			tab[n-x]='a';
			tab[n-x-1]++;
			
			while(tab[n-x]==tab[n-x+1] || tab[n-x]==tab[n-x+2] || tab[n-x]==tab[n-x-1] || tab[n-x]==tab[n-x-2] || (tab[n-x]=='a' && tab[n-x-1]>122))
			{
				tab[n-x]++;
			}
			
			x++;
			
		}
		
		x=1;
	}
	
	for(int i=0; i<n; i++)	
	cout<<tab[i];
	
}
