#include<bits/stdc++.h>
using namespace std;

long long sum, i;
vector<int> primes;

bool isprime(int n)
{
	if(n<2) return false;
	
	for(int i=2; i*i<=n; i++)
	if(n%i==0) return false;
	
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	while(1)
	{
		i++;
		if(isprime(i))
		sum+=i;
		
		if(sum>=1e8)
		break;
	}
	
	cout<<sum<<" "<<i;
	
	
}
