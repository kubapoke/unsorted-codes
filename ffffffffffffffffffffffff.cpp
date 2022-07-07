#include<iostream>
using namespace std;

int main()
{
	//5 3 4 3 2 4 1 2 1 3 5 1 4 1
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, w=0;
	
	cin>>n;
	
	int tab[n];
	
	
	
	for(int i=0; i<n; i++)
	cin>>tab[i];
	
	if(n==1 && tab[0]==1)
	{
		cout<<"1";
		return 0;
	}
	
	for(int i=0; i<n; i++)
	{
		if(i==0)
		{
			if(tab[n-1]==1 && tab[n-2]!=1)
			{
				tab[n-1]=0;
				tab[0]=0;
				tab[1]=0;
				w++;
			}
		}
		else if(i!=n-1)
		{
			if(tab[i-1]==1 && i!=1)
			{
				tab[i-1]=0;
				tab[i]=0;
				tab[i+1]=0;
				w++;
			}
		}
		else
		{
			if(tab[i-1]==1 || tab[i]==1)
			{
				tab[i-1]=0;
				tab[i]=0;
				w++;
			}
		}
	}
	
	cout<<w;
}
