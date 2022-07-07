#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	register int n, w=0;
	
	cin>>n;
	
	while(n>=500)
	{
		n-=500;
		w++;
	}
	while(n>=200)
	{
		n-=200;
		w++;
	}
	while(n>=100)
	{
		n-=100;
		w++;
	}
	while(n>=50)
	{
		n-=50;
		w++;
	}
	while(n>=20)
	{
		n-=20;
		w++;
	}
	while(n>=10)
	{
		n-=10;
		w++;
	}
	while(n>=5)
	{
		n-=5;
		w++;
	}
	while(n>=2)
	{
		n-=2;
		w++;
	}
	while(n>=1)
	{
		n-=500;
		w++;
	}
	
	cout<<w;
	
}
