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
	
	char tab[a][b];
	
	for(int i=0; i<a; i++)
	for(int j=0; j<b; j++)
	cin>>tab[i][j];
	
	cin>>q;
	
	for(int i=0; i<q; i++)
	{
		cin>>c>>x>>y;
		
		x--;
		y--;
		
		if(tab[x][y]==c)
		{
			w+=1;
			continue;	
		}	
		if(x!=a-1&&y!=b-1)
		{ 
			if (tab[x+1][y+1]==c)
			{
				w+=0.5;
				continue;	
			}	
		}
		if(x!=a-1)
		{ 
			if (tab[x+1][y+1]==c)
			{
				w+=0.5;
				continue;	
			}	
		}
		if(y!=b-1)
		{ 
			if (tab[x+1][y+1]==c)
			{
				w+=0.5;
				continue;	
			}	
		}
		if(x!=0&&y!=b-1)
		{ 
			if (tab[x+1][y+1]==c)
			{
				w+=0.5;
				continue;	
			}	
		}
		if(y!=0&&x!=a-1)
		{
			if (tab[x+1][y+1]==c)
			{
				w+=0.5;
				continue;	
			}	
		}
		if(x!=0&&y!=0)
		{ 
			if (tab[x+1][y+1]==c)
			{
				w+=0.5;
				continue;	
			}	
		}
		if(y!=0)
		{ 
			if (tab[x+1][y+1]==c)
			{
				w+=0.5;
				continue;	
			}	
		}
		if(x!=0)
		{ 
			if (tab[x+1][y+1]==c)
			{
				w+=0.5;
				continue;	
			}	
		}
	}
	
	cout<<w;
}
