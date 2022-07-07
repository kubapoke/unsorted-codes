#include<bits/stdc++.h>
using namespace std;

long long n, w, x, l;
vector<long long> pierwsze;

int main()
{
	cin>>n;
	x=n; w=n;
	
	l=2;
	
	while(x!=1 && l*l<=n)
	{
		if(x%l==0)
		{
			pierwsze.push_back(l);
			while(x%l==0)
			x/=l;
		}
		
		l++;
	}
	
	if(x!=1)
	pierwsze.push_back(x);
	
	for(int i=1; i<(1<<pierwsze.size()); i++)
	{
		int s=i, ile=0, liczba=0;
		long long iloczyn=1;
		
		while(s)
		{
			if(s%2==1)
			{
				iloczyn*=pierwsze[liczba];
				ile++;
			}
			
			s/=2;
			liczba++;
		}
		
		if(ile%2==1)
		w-=(n/iloczyn);
		else
		w+=(n/iloczyn);
	}
	
	cout<<w;
}
