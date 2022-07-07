#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	long long m, a, b, x;
	
	cin>>m;
	
	if(m%2!=0)
	return 0;
	
	int v=0;
	
	for(int i=1; i<=m/2; i++)
	{
		cin>>a;
		cin>>b;
		
		if(a%2!=b%2)
		{
			x=a;
			a=b;
			b=x;
		}
		
		a/=10;
		
		b=b*b*b;
		
		if(a==b)
		v++;
	}
		
	cout<<v;	
}
