#include<bits/stdc++.h>
using namespace std;

int n, w, tab[2001][2001], czy[2001];

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>n;
	for(int i=0; i<n; i++)
	{
		int a, b;
		cin>>a>>b;
		tab[a+1000][b+1000]=1;
		czy[a+1000]++;
	}

	for(int i=0; i<=2000; i++)
	{
		if(czy[i]==0)
		continue;
		
		for(int x=0; x<=2000; x++)
		{
			if(tab[i][x]==1)
			for(int y=x+1; y<=2000; y++)
			{
				int roz=abs(y-x);
				
				if(i+roz>2000)
				break;
				
				if(tab[i][y]==1)
				if(tab[i+roz][x]==1&&tab[i+roz][y]==1)
				w++;
				
			}
		}
	}
	
	cout<<w;
}
