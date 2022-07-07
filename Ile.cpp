#include<iostream>
using namespace std;

int main()
{
	int a=0, c=0;
	
	while(a%15!=0 || a==0)
	{
		cin>>a;
		if(a%15!=0 && (a%3==0 || a%5==0))
		c++;
	}
	
	cout<<c;
	
	return 0;
}
