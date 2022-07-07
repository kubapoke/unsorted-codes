#include<bits/stdc++.h>
using namespace std;

int n, a, b, c;

int main()
{
	cin>>n;
	
	c=n%10;
	n/=10;
	b=n%10;
	n/=10;
	a=n;
	
	if(a<=b&&b<=c)
	cout<<"TAK";
	else
	cout<<"NIE";
}
