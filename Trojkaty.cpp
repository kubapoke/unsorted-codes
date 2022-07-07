#include<iostream>
using namespace std;

int main()
{
	int a, b, c;
	
	cin>>a>>b>>c;
	
	char x;
	
	if(a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a)
	x='P';
	else if(a*a+b*b<c*c||a*a+c*c<b*b||b*b+c*c<a*a)
	x='R';
	else
	x='O';
	
	cout<<x;
	
	return 0;
}
