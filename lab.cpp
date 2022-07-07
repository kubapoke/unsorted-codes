#include<iostream>
#include <iomanip>      
using namespace std;

int main()
{
	ios_base::sync_with_stdio;
	cin.tie(0);
	
	int c=1, l=1, x=24, y=24;
	int tab[50][50];
	
	for(int i=0; i<50; i++)
	for(int j=0; j<50; j++)
	tab[i][j]=0;
	
	tab[24][24]=1;
	
	while(tab[49][49]==0)
	{
		if(l==1)
		{
			for(int i=0; i<c; i++)
			{
				x++;
				tab[x][y]=1;
			}
			c++;
			l++;
		}
		if(l==2)
		{
			for(int i=0; i<c; i++)
			{
				y++;
				tab[x][y]=1;
			}
			c++;
			l++;
		}
		if(l==3)
		{
			for(int i=0; i<c; i++)
			{
				x--;
				tab[x][y]=1;
			}
			c++;
			l++;
		}
		if(l==4)
		{
			for(int i=0; i<c; i++)
			{
				y--;
				tab[x][y]=1;
			}
			c++;
			l=1;
		}	
	}
	
	
	for(int i=0; i<50; i++)
	{
		for(int j=0; j<50; j++)
		{
			if(tab[i][j]==0)
			cout<<"#";
			else
			cout<<".";
		}
		cout<<'\n';
	}
	
	
	
	return 0;
}
