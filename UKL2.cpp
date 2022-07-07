#include<bits/stdc++.h>
using namespace std;

long long n, m, p, f=1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	
	for(long long i=3ll; i<=n; i++)
	f=((f%m)*(i%m))%m;
	
	
	if(n==2)
	p=1;
	else
	p=(n-1)*(n-3)+(n-1)*(n-1)+n-2;
	
	cout<<((p%m)*(f%m))%m;
	
	return 0;
}
