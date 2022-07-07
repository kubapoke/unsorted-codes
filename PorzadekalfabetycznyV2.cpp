#include<bits/stdc++.h>
using namespace std;

string tab[500];
int n, l, a1, a2=1e9;
int posort[20005], przes[20005], wartprzes[505][20005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>l;
	
	for(int i=0; i<n; i++)
	cin>>tab[i];
	
	if(n==1)
	{
		cout<<"1 1";
		return 0;
	}
	
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
	
	for(int i=0; i<l; i++)
	{
		if(posort[i]==2)
		posort[i]=0;
	}
	
	for(int i=l-1; i>=0; i--)
	{
		for(int j=1; j<n; j++)
		{
			if(tab[j][i]==tab[j-1][i])
			{
				wartprzes[j][i]=1+wartprzes[j][i+1];
				
				przes[i]=max(przes[i],wartprzes[j][i]);
			}
		}
	}
	
	for(int i=0; i<l; i++)
	{
		if(posort[i])
		{
			if(przes[i]<a2-a1 && i+przes[i]<l)
			{
				a1=i+1;
				a2=i+przes[i]+1;
			}
		}
	}
	
	cout<<a1<<" "<<a2;
	
	/*
	for(int i=0; i<l; i++)
	cout<<posort[i]<<" ";
	cout<<"\n\n";
	
	for(int i=0; i<l; i++)
	cout<<przes[i]<<" ";
	cout<<"\n\n";
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<l; j++)
		cout<<wartprzes[i][j];
		cout<<"\n";
	}
	*/
}
