#include<iostream>
using namespace std;


int main()
{
	int n, m, a=1, b=1, c;
	
	cin>>n>>m;

	
	for(int i=2; i<=n; i++)
	{
		c=(a+b)%m;
		
		a=b;
		b=c;
	}
	
	cout<<c;
}
