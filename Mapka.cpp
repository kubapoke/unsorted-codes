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
	
	register int a, b, q, x, y;
	register float w=0;
	register char c;
	
	cin>>a>>b;
	
	char tab[b+2][a+2];
	
	for(int i=1; i<b; i++)
	for(int j=1; j<a; j++)
	cin>>tab[i][j];
	
	for(int i=0; i<b; i++)
	{
		tab[i][0]=0;
		tab[i][a+1]=0;
	}
	
	for(int i=0; i<a; i++)
	{
		tab[0][i]=0;
		tab[b+1][i]=0;
	}
	
	
	
	cin>>q;
	
	for(int i=0; i<q; i++)
	{
		cin>>c>>x>>y;
		
		x--;
		y--;

		if(x!=b-1&&y!=a-1)
		{ 
			if (tab[x+1][y+1]==c)
			w+=0.5;
		}
		if(x!=b-1)
		{ 
			if (tab[x+1][y]==c)
			w+=0.5;
		}
		if(y!=a-1)
		{ 
			if (tab[x][y+1]==c)
			w+=0.5;
		}
		if(x!=0&&y!=a-1)
		{ 
			if (tab[x-1][y+1]==c)
			w+=0.5;
		}
		if(y!=0&&x!=b-1)
		{
			if (tab[x+1][y-1]==c)
			w+=0.5;
		}
		if(x!=0&&y!=0)
		{ 
			if (tab[x-1][y-1]==c)
			w+=0.5;
		}
		if(y!=0)
		{ 
			if (tab[x][y-1]==c)
			w+=0.5;
		}
		if(x!=0)
		{ 
			if (tab[x-1][y]==c)
			w+=0.5;
		}
	}
	
	cout<<w;
}
