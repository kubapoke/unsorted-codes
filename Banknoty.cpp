#include<bits/stdc++.h>
using namespace std;

int n, b[20001], c[20001], k, dp[201][20001], ile[201][20001];
deque<pair<int,int>> qmax;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	for(int i=1; i<=n; i++) cin>>b[i];
	for(int i=1; i<=n; i++) cin>>c[i];
	
	cin>>k;
	
	for(int i=0; i<=200; i++)
	for(int j=0; j<=20000; j++)
	dp[i][j]=1e9;
	
	
}
