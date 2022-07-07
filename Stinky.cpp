#include<iostream>
using namespace std;

int main()
{
	long long n, c=1;
	
	cin>>n;
	
	char tab[100];
	
	for(int i=0; i<100; i++)
	{
		tab[i]='0';
	}
	
	while(n!=1)
	{
		if(n%2==0)
		{
			tab[c]='L';
			n/=2;
		}
		else
		{
			tab[c]='P';
			n/=2;
		}
		c++;
	}
	
	for(int i=99; i>=0; i--)
	{
		if(tab[i]!='0')
		cout<<tab[i];
	}
}
