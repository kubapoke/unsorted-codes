#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	register int m, n, z, s=0, s2=0, x=1, mw=1, dw=1, dz, ms;
	register char c;
	
	cin>>m>>n;
	
	int a[m+1], b[n+1];
	
	//miesi¹ce arbuzan
	
	for(int i=1; i<=m; i++)
	{
		cin>>a[i];
	}
	
	//miesi¹ce bananitów
	
	for(int i=1; i<=n; i++)
	{
		cin>>b[i];
	}
	
	//zapytania
	
	cin>>z;
	
	for(int i=0; i<z; i++)
	{
		cin>>dz>>ms>>c;
		
		if(c=='A')
		{
			for(int j=1; j<ms; j++)
			{
				s+=a[j];
			}
			
			s+=dz;
			
			while(s2+b[x]<s)
			{
				s2+=b[x];
				
				mw++;
				x++;
			}
			
			dw=s-s2;
			
			cout<<dw<<" "<<mw<<"\n";
			
			mw=1; dw=1, x=1;
		}
		
		else if(c=='B')
		{
			for(int j=1; j<ms; j++)
			{
				s+=b[j];
			}
			
			s+=dz;
			
			while(s2+a[x]<s)
			{
				s2+=a[x];
				
				mw++;
				x++;
			}
			
			dw=s-s2;
			
			cout<<dw<<" "<<mw<<"\n";
			
			mw=1; dw=1, x=1;
		}
		
		s=0;
		s2=0;
	}
	
	return 0;
}
