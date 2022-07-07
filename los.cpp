#include<bits/stdc++.h>
#define more dp[1001]
using namespace std;

int n, g, w, p;
long long dp[1002], INF=1e18+1;;

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>n>>g;
	
	for(int i=1; i<=g; i++)
	dp[i]=INF;
	
	more=INF;
	
	for(int i=0; i<n; i++)
	{
		cin>>w>>p;
		
		if(w==0)
		continue;
		
		for(int j=g; j>=0; j--)
		{
			if(dp[j]!=INF)
			{
				if(j+w<=g)
				dp[j+w]=min(dp[j+w], dp[j]+p);
				else
				more=min(more, dp[j]+p);
			}
		}
	}
	
	if(dp[g]==INF&&more==INF)
	cout<<"NIE";
	else
	cout<<min(more, dp[g])+g;
}
