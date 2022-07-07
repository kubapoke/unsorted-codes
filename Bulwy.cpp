#include<iostream>
#include<cmath>
#include<math.h>
#include<iomanip>
#include<algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	register long long n, b, m, w=0;
	
	cin>>n;
	
	int tab[n];
	
	for(int i=0; i<n; i++)
	cin>>tab[i];
	
	sort(tab, tab+n);
	
	cin>>m;
	
	for(int i=n-1; i>=0; i--)
	{
		if(m>tab[i])
		{
			w+=tab[i]*tab[i];
			m-=tab[i];
		}
		else
		{
			w+=m*m;
			break;
		}
	}
	
	cout<<w;
	
}
