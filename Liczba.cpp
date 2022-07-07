#include<iostream>
using namespace std;

int main()
{
	long long n, s=2;
	
	cin>>n;
	
	do
	{
		if(n%s!=0)
		{
			cout<<s<<" ";
			break;
		}
	
		s++;
	}
	while(1);
	
	s=n-1;
	
	do
	{
		if(n%s!=0)
		cout<<s;
		
		s--;
	}
	while(n%s==0);
	
	
	return 0;
}
