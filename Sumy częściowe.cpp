#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	register int n, c=0, z, sk;
	
	cin>>n;
	
	int tab[n][n];
	
	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
	cin>>tab[i][j];
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			c+=tab[i][j];
			
			z=i-1;
			
			while(z>=0)
			{
				c+=tab[z][j];
				
				z--;
			}
			
			cout<<c<<" ";
		}
		c=0;
		
		cout<<endl;
	}
	
	return 0;
}
