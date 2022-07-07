#include<bits/stdc++.h>
using namespace std;

long long n, w=0, d=0, fib[88];
vector<long long> dziel;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	
	fib[1]=1; fib[2]=2;
	
	for(int i=3; i<88; i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
	}
	
	for(int i=87; i>=2; i--)
	{
		if(n%fib[i]==0)
		dziel.push_back(fib[i]);
	}
	
	if(!dziel.size())
	cout<<"NIE";
}
