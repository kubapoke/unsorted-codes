#include<bits/stdc++.h>
using namespace std;

long long A, B, ans;

long long romb(long long n)
{
	long long odp=n;
	
	while(n)
	{
		odp*=(n%10);
		n/=10;
	}
	
	return odp;
}

void getans(long long x)
{
	long long r=romb(x);
	
	if(r>B)
	return;
	
	
	if(r>=A)
	ans++;
	
	long long l=x*10;
	
	getans(++l);
	getans(++l);
	getans(++l);
	getans(++l);
	getans(++l);
	getans(++l);
	getans(++l);
	getans(++l);
	getans(++l);
}

int main()
{
	cin>>A>>B;
	
	getans(0);
	
	cout<<ans;
}
