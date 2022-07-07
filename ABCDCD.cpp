#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

string s;
long long tab[256][5000], ileAB[5000], pop[256];
long long CD[256][256], tempCD[256][256], posC[256], ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>s;
	int n=s.size();
	
	for(int i=0; i<256; i++)
	pop[i]=-1;
	
	for(int i=0; i<n; i++)
	{
		if(i)
		ileAB[i]+=ileAB[i-1];
		
		tab[s[i]][i]++;
		
		for(int j='0'; j<='9'; j++)
		{
			if(i)
			tab[j][i]+=tab[j][i-1];
			
			if(j!=s[i] && tab[j][i] && (!tab[j][pop[s[i]]] || pop[s[i]]==-1))
			ileAB[i]++;
		}
		
		for(int j='a'; j<='z'; j++)
		{
			if(i)
			tab[j][i]+=tab[j][i-1];
			
			if(j!=s[i] && tab[j][i] && (!tab[j][pop[s[i]]] || pop[s[i]]==-1))
			ileAB[i]++;
		}
		
		for(int j='A'; j<='Z'; j++)
		{
			if(i)
			tab[j][i]+=tab[j][i-1];
			
			if(j!=s[i] && tab[j][i] && (!tab[j][pop[s[i]]] || pop[s[i]]==-1))
			ileAB[i]++;
		}
		
		pop[s[i]]=i;
		
		ileAB[i]%=mod;
	}
	
	/////dot¹d jest gituwa
	
	for(int i=0; i<n; i++)
	{
		posC[s[i]]=i;
		
		for(int j='0'; j<='9'; j++)
		{
			if(tab[j][n-1]>tab[j][i] && j!=s[i] && posC[j])
			{
				tempCD[j][s[i]]=max(tempCD[j][s[i]], ileAB[posC[j]-1]);
			}
			
			if(tempCD[s[i]][j])
			{
				if(tab[s[i]][n-1]>tab[s[i]][i])
				CD[s[i]][j]=tempCD[s[i]][j];
			}
		}
		
		for(int j='a'; j<='z'; j++)
		{
			if(tab[j][n-1]>tab[j][i] && j!=s[i] && posC[j]) //j to C, s[i] to D
			{
				tempCD[j][s[i]]=max(tempCD[j][s[i]], ileAB[posC[j]-1]);
			}
			
			if(tempCD[s[i]][j]) //s[i] to C, j to D
			{
				if(tab[s[i]][n-1]>tab[s[i]][posC[j]])
				CD[s[i]][j]=tempCD[s[i]][j];
			}
		}
		
		for(int j='A'; j<='Z'; j++)
		{
			if(tab[j][n-1]>tab[j][i] && j!=s[i] && posC[j])
			{
				tempCD[j][s[i]]=max(tempCD[j][s[i]], ileAB[posC[j]-1]);
			}
			
			if(tempCD[s[i]][j])
			{
				if(tab[s[i]][n-1]>tab[s[i]][i])
				CD[s[i]][j]=tempCD[s[i]][j];
			}
		}
	}
	
	for(int i=0; i<n; i++)
	cout<<ileAB[i]<<" ";
	cout<<"\n";
	
	for(int i=0; i<256; i++)
	for(int j=0; j<256; j++)
	ans=(ans%mod+CD[i][j])%mod;
	
	cout<<ans;
}
