#include<bits/stdc++.h>
using namespace std;

long long n, m, p, f=1, a;

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
	p=(((((((n%m)-(1%m)+m)%m)*(((n%m)-(3%m)+m)%m))%m+((((n%m)-(1%m)+m)%m)*(((n%m)-(1%m)+m)%m))%m)%m+n%m)%m-2%m+m)%m;
	
	cout<<(((p%m)*(f%m)))%m;
	
}
