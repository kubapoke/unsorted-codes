#include<bits/stdc++.h>
#define B 1e9
using namespace std;

int ans;

set<long long> odp;

void generate(long long n)
{
	if(n<=B)
	{
		odp.insert(n);
		
		if(min(n%3,min(n%5,n%7)))
		generate(n*2);
		
		if(min(n%5,n%7))
		generate(n*3);
		
		if(n%7)
		generate(n*5);
		
		generate(n*7);
	}
}




int main()
{
	generate(1);
	
	cout<<odp.size();
}
