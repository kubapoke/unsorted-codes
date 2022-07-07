#include<bits/stdc++.h>
using namespace std;

long long A, B, dp[19][70000];
vector<long long> W;
set<long long> S;

void gen7(long long n)
{
	if(n<B)
	{
		W.push_back(n);
		
		gen7(n*7);
	}
}

void gen5(long long n)
{
	if(n<B)
	{
		W.push_back(n);
		
		gen5(n*5);
		gen7(n*7);
	}
}

void gen3(long long n)
{
	if(n<B)
	{
		W.push_back(n);
		
		gen3(n*3);
		gen5(n*5);
		gen7(n*7);
	}
}

void gen2(long long n)
{
	if(n<B)
	{
		W.push_back(n);
		
		gen2(n*2);
		gen3(n*3);
		gen5(n*5);
		gen7(n*7);
	}
}


int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(0); cout.tie(0);
	
	cin>>A>>B;
	
	W.push_back(1);
	gen2(2); gen3(3); gen5(5); gen7(7);
	
	cout<<W.size();
	
	for(int k=1; k<=18; k++)
	for(int w=0; w<W.size(); w++)
	{
		dp[k][w]+=dp[k-1][w]
		
		for(int =1; i<=9; i++)
		{
			if(v%i==0)
			dp[{k,v}]+=dp[{k-1,v/i}];
		}
	}
	
}
