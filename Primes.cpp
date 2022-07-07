#include<bits/stdc++.h>
#define N 1e8
using namespace std;

vector<int> primes;
map<int,vector<int>> liczby;

bool isprime(int n)
{
	if(n<2) return false;
	
	for(int i=2; i*i<=n; i++)
	if(n%i==0) return false;
	
	return true;
}

void getsums(int i)
{
	int sum=0;
	
	for(int j=i; j<primes.size(); j++)
	{
		sum+=primes[j];
		
		//cout<<"["<<primes[i]<<", "<<primes[j]<<"]: "<<sum<<" ("<<j-i+1<<")\n";
		
		liczby[j-i+1].push_back(sum);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	for(int i=0; i<=N; i++)
	if(isprime(i)) primes.push_back(i);
	
	/*
	for(auto u: primes)
	cout<<u<<" ";
	*/
	
	for(int i=0; i<primes.size(); i++)
	getsums(i);
	
	/*
	for(auto it: liczby)
	{
		cout<<it.first<<":  ";
		for(auto u: it.second)
		cout<<u<<" ";
		cout<<"\n";
	}
	*/
}
