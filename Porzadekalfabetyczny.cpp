#include<bits/stdc++.h>
using namespace std;

string tab[500];
int n, l;
int posort[20000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>l;
	
	for(int i=0; i<n; i++)
	cin>>tab[i];
	
	for(int i=0; i<l; i++)
	{
		posort[i]=2;
		
		for(int j=1; j<n; j++)
		{
			if(tab[j][i]<tab[j-1][i])
			{
				posort[i]=0;
				break;
			}
			if(tab[j][i]!=tab[j-1][i])
			{
				posort[i]=1;
			}
		}
	}
	
	for(int i=l-1; i>=0; i--)
	{
		if(posort[i]==2)
		{
			if(i==l-1)
			posort[i]=1;
			else
			posort[i]=posort[i+1];
		}
	}
	
	for(int i=0; i<l; i++)
	cout<<posort[i]<<" ";
	
	
}
