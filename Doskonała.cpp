#include<iostream>
using namespace std;

int main()
{
	int a, s=0;
	
	cin>>a;
	
	for(int i=1; i*i<=a; i++)
	{
		if(a%i==0)
		{
			s=s+i;
			s=s+a/i;
		}
	}
	
	s=s-a;
	
	if(s==a && a!=1)
	cout<<"DOSKONALA";
	else
	cout<<"NIE";
	
	return 0;
}
