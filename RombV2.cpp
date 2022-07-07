#include<bits/stdc++.h>
using namespace std;

long long A, B, ans;
vector<long long> W;
unordered_map<long long,int> dp[20];

void gen7(long long n)
{
	if(n<=sqrt(B))
	{
		W.push_back(n);
		
		gen7(n*7);
	}
}

void gen5(long long n)
{
	if(n<=sqrt(B))
	{
		W.push_back(n);
		
		gen5(n*5);
		gen7(n*7);
	}
}

void gen3(long long n)
{
	if(n<=sqrt(B))
	{
		W.push_back(n);
		
		gen3(n*3);
		gen5(n*5);
		gen7(n*7);
	}
}

void gen2(long long n)
{
	if(n<=sqrt(B))
	{
		W.push_back(n);
		
		gen2(n*2);
		gen3(n*3);
		gen5(n*5);
		gen7(n*7);
	}
}

long long f(long long C, long long w)
{	
	if(C==0)
	return 0;
	
	int najzn, l=1;
	long long D=1, odp=0, reszta;
	
	while(C/D>=10)
	{
		D*=10; l++;
	}
	najzn=C/D;
	reszta=C%D;
	
	if(l==1)
	return dp[1][w];
	
	for(int i=1; i<najzn; i++)
	{
		if(w%i==0)
		odp+=dp[l-1][w/i];
	}
	
	if(w%najzn==0)
	odp+=f(reszta, w/najzn);
	
	return odp;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>A>>B;
	//A=11; B=49;
	
	W.push_back(1);
	gen2(2); gen3(3); gen5(5); gen7(7);
	
	for(int i=0; i<=9; i++)
	{
		dp[1][i]=1;
	}
		
	for(int k=2; k<=19; k++)
	for(auto it: W)
	{
		for(int i=1; i<=9; i++)
		{
			if(it%i==0)
			dp[k][it]+=dp[k-1][it/i];
		}
	}
	//tu dp[i][j] = ile jest k-cyfrowych liczb o iloczynie cyfr równych j
	
	//for(auto it: W)
	//for(int k=1; k<=19; k++)
	//dp[k][it]+=dp[k-1][it];	
	
	//tu dp[i][j] = ile jest [1,k]-cyfrowych liczb o iloczynie cyfr równych j
	
	for(auto it: W)
	ans+=f(B/it,it)-f((A-1)/it,it);
	cout<<ans;

}
