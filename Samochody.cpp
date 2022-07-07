#include<iostream>
using namespace std;

int main()
{
	long long n, a, c=0, wyn=0;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>a;
		if(a==0)
		{
			c++;
		}
		else
		{
			wyn=wyn+c;
		}
	}
	
	cout<<wyn;
	
	return 0;
}
