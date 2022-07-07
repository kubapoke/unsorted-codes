#include<bits/stdc++.h>
using namespace std;

long long a, b, ans;

long long romb(long long n)
{
	long long ans=n;
	
	while(n)
	{
		ans*=(n%10);
		n/=10;
	}
	
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>a>>b;
	
	long long sa, sb;
	sa=floor(sqrt(a)); sb=ceil(sqrt(b));
	
	for(int i=a; i<=b; i++)
	{
		long long R=romb(i);
		
		if(R>=a && R<=b)
		ans++;
	}
	
	cout<<ans;
}
