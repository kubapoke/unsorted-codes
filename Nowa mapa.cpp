#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	register int x, y, n, a, b;
	register float w=0;
	register char c;
	
	cin>>x>>y;
	
	char tab[x+2][y+2];
	
	for(int i=1; i<=x; i++)
	for(int j=1; j<=y; j++)
	cin>>tab[i][j];
	
	for(int i=1; i<=x; i++)
	for(int j=1; j<=y; j++)
	{
		tab[i][0]='0';
		tab[i][y+1]='0';
		tab[0][j]='0';
		tab[x+1][j]='0';
	}
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>c>>a>>b;
		
		if(tab[a][b]==c)
		w++;
		else if(tab[a+1][b+1]==c||tab[a+1][b]==c||tab[a][b+1]==c||tab[a-1][b-1]==c||tab[a-1][b]==c||tab[a][b-1]==c||tab[a+1][b-1]==c||tab[a-1][b+1]==c)
		w+=0.5;
	}
	
	cout<<w;
}
