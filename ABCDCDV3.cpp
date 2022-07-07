#include<bits/stdc++.h>
#define mod 1000000007
#define inv 500000004
using namespace std;

string s;
long long ans, SUM, dp[256][256][5], S[256], L[256];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>s;
	int n=s.size();
	
	for(int i=0; i<n; i++)
	L[s[i]]++;
	
	for(int i=n-1; i>=0; i--)
	{
		char c=s[i];
		L[c]--; //ubywa jednej takiej po lewej
		
		for(int j='a'; j<='z'; j++)
		{
			if(j==c)
			continue;
			
			ans+=((L[j]%mod) * ((((SUM%mod)*inv-S[j]%mod-S[c]%mod+dp[j][c][4]%mod+dp[c][j][4]%mod+mod))%mod))%mod;
			ans%=mod;
		}
		for(int j='A'; j<='Z'; j++)
		{
			if(j==c)
			continue;
			
			ans+=((L[j]%mod) * ((((SUM%mod)*inv-S[j]%mod-S[c]%mod+dp[j][c][4]%mod+dp[c][j][4]%mod+mod))%mod))%mod;
			ans%=mod;
		}
		for(int j='0'; j<='9'; j++)
		{
			if(j==c)
			continue;
			
			ans+=((L[j]%mod) * ((((SUM%mod)*inv-S[j]%mod-S[c]%mod+dp[j][c][4]%mod+dp[c][j][4]%mod+mod))%mod))%mod;
			ans%=mod;
		}

		for(int j='a'; j<='z'; j++)
		{
			if(j==c)
			continue;
			dp[c][j][1]=(dp[c][j][1]+1)%mod;
			dp[j][c][2]=(dp[j][c][2]+dp[j][c][1])%mod;
			dp[c][j][3]=(dp[c][j][3]+dp[c][j][2])%mod;
			dp[j][c][4]=(dp[j][c][4]+dp[j][c][3])%mod;
			S[c]=(S[c]+dp[j][c][3])%mod; S[j]=(S[j]+dp[j][c][3])%mod; SUM=(SUM + dp[j][c][3] + dp[j][c][3])%mod;	
		}
		for(int j='A'; j<='Z'; j++)
		{
			if(j==c)
			continue;
			dp[c][j][1]=(dp[c][j][1]+1)%mod;
			dp[j][c][2]=(dp[j][c][2]+dp[j][c][1])%mod;
			dp[c][j][3]=(dp[c][j][3]+dp[c][j][2])%mod;
			dp[j][c][4]=(dp[j][c][4]+dp[j][c][3])%mod;
			S[c]=(S[c]+dp[j][c][3])%mod; S[j]=(S[j]+dp[j][c][3])%mod; SUM=(SUM + dp[j][c][3] + dp[j][c][3])%mod;	
		}
		for(int j='0'; j<='9'; j++)
		{
			if(j==c)
			continue;
			dp[c][j][1]=(dp[c][j][1]+1)%mod;
			dp[j][c][2]=(dp[j][c][2]+dp[j][c][1])%mod;
			dp[c][j][3]=(dp[c][j][3]+dp[c][j][2])%mod;
			dp[j][c][4]=(dp[j][c][4]+dp[j][c][3])%mod;
			S[c]=(S[c]+dp[j][c][3])%mod; S[j]=(S[j]+dp[j][c][3])%mod; SUM=(SUM + dp[j][c][3] + dp[j][c][3])%mod;	
		}
	}
	
	cout<<ans;
}
