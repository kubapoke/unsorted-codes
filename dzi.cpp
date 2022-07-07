#include<bits\stdc++.h>
using namespace std;

int n, a, maks, lic=1, mn=1;
int d[2001][2001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	
	for(int i=1; i<=n; i++)
	for(int j=1; j<=n; j++)
	{
		cin>>a;
		
		if(a==0)
		d[i][j]=d[i][j-1]+1;
	}
	/*
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		cout<<d[i][j]<<" ";
		cout<<"\n";
	}
	*/
	for(int j=1; j<=n; j++)
	{
		lic=1; mn=1;
		
		for(int i=1; i<=n; i++)
		{
			if(d[i][j]!=0)
			{
				if(d[i][j-1]==0)
				{
					d[i][j]=max(lic, d[i][j]);
					mn=1;
				}
				else
				{
					d[i][j]*=mn;
					mn++;
				}
				lic++;
				if(d[i][j]>maks)
				maks=d[i][j];
			}
			else
			{
				lic=1; mn=1;
			}
		}
	}
	
	cout<<"\n";
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		cout<<d[i][j]<<" ";
		cout<<"\n";
	}
	cout<<"\n";
	
	cout<<maks;
}
