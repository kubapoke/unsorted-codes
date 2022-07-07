#include<bits/stdc++.h>
using namespace std;

long long A, B;
vector<long long> W;
int dp[19][60][38][26][22];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>A>>B;
	
	dp[1][1][0][0][0]=1; //2
	dp[1][0][1][0][0]=1; //3
	dp[1][2][0][0][0]=1; //4
	dp[1][0][0][1][0]=1; //5
	dp[1][1][1][0][0]=1; //6
	dp[1][0][0][0][1]=1; //7
	dp[1][3][0][0][0]=1; //8
	dp[1][0][2][0][0]=1; //9
		
	for(int k=2; k<19; k++)
	for(int a=0; a<60; a++)
	for(int b=0; b<38; b++)
	for(int c=0; c<26; c++)
	for(int d=0; d<22; d++)
	{
		dp[k][a][b][c][d]+=dp[k-1][a][b][c][d]; //0
		dp[k][a][b][c][d]+=dp[k-1][a][b][c][d]; //1
		if(a>=1)
		dp[k][a][b][c][d]+=dp[k-1][a-1][b][c][d]; //2
		if(b>=1)
		dp[k][a][b][c][d]+=dp[k-1][a][b-1][c][d]; //3
		if(a>=2)
		dp[k][a][b][c][d]+=dp[k-1][a-2][b][c][d]; //4
		if(c>=1)
		dp[k][a][b][c][d]+=dp[k-1][a][b][c-1][d]; //5
		if(a>=1 && b>=1)
		dp[k][a][b][c][d]+=dp[k-1][a-1][b-1][c][d]; //6
		if(d>=1)
		dp[k][a][b][c][d]+=dp[k-1][a][b][c][d-1]; //7
		if(a>=3)
		dp[k][a][b][c][d]+=dp[k-1][a-3][b][c][d]; //8
		if(b>=2)
		dp[k][a][b][c][d]+=dp[k-1][a][b-2][c][d]; //9
	}

}
