#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

string s;
long long tab[256][5000], ileAB[5000];
long long CD[256][256], tempCD[256][256], posC[256], ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>s;
	int n=s.size();
	
	for(int i=0; i<n; i++)
	{
		if(i)
		ileAB[i]+=ileAB[i-1];
		
		tab[s[i]][i]++;
		
		for(int j='0'; j<='9'; j++)
		{
			if(i)
			tab[j][i]+=tab[j][i-1];
			
			if(j!=s[i])
			ileAB[i]+=tab[j][i];
		}
		
		for(int j='a'; j<='z'; j++)
		{
			if(i)
			tab[j][i]+=tab[j][i-1];
			
			if(j!=s[i])
			ileAB[i]+=tab[j][i];
		}
		
		for(int j='A'; j<='Z'; j++)
		{
			if(i)
			tab[j][i]+=tab[j][i-1];
			
			if(j!=s[i])
			ileAB[i]+=tab[j][i];
		}
		
		ileAB[i]%=mod;
	}
	
	/////dot¹d jest gituwa
	
	for(int i=0; i<n; i++)
	{
		for(int j='a'; j<='z'; j++)
		{
			if(tab[j][n-1]>tab[j][i] && j!=s[i]) //j to C, s[i] to D
			{
				tempCD[j][s[i]]=(tempCD[j][s[i]]%mod + ileAB[posC[j]-1]%mod)%mod;
			}
			
			if(tempCD[s[i]][j]) //s[i] to C, j to D
			{
				if(tab[s[i]][n-1]>tab[s[i]][posC[j]])
				CD[s[i]][j]=tempCD[s[i]][j];
			}
		}
	}
	
	for(int i=0; i<n; i++)
	cout<<ileAB[i]<<" ";
	cout<<"\n";
	
	//for(int i=0; i<256; i++)
	//for(int j=0; j<256; j++)
	//ans=(ans%mod+CD[i][j])%mod;
	
	//cout<<ans;
}
