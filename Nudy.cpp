#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	register int n, m, a, c, pocz, kon, sr;
	
	cin>>n;
	
	int tab[n+1];
	
	tab[n]=1000001;
	
	for(int i=0; i<n; i++)
	cin>>tab[i];
	
	cin>>m;
	
	for(int i=0; i<m; i++)
	{
		cin>>c;	
		
		pocz=0; kon=n; sr=(pocz+kon)/2;
		
		while(tab[sr]<c || tab[sr-1]>=c)
		{
			if(tab[sr]<c)
			{
				pocz=sr+1;
			}
			else
			{
				kon=sr-1;
			}
			sr=(pocz+kon)/2;
		}
		
		cout<<sr<<"\n";
		
	}
	
	return 0;
}
