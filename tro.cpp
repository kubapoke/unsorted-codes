#include<bits/stdc++.h>
using namespace std;

int a,b,c,x,y;

int main()
{
	cin>>a>>b>>c;
	
	x=max(a,max(b,c));
	y=a+b+c-x;
	
	if(x<y)
	cout<<"TAK";
	else
	cout<<"NIE";
}
