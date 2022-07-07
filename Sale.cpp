#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int a, b, c, d, r1, r2;
	
	
	cin>>a>>b>>c>>d;
	
	if(a==b==c==d)
	r1=a*a;
	else
	{
		if(a!=b)
		r1=a*b;
		else if(a!=c)
		r1=a*c;
		else
		r1=a*d;
	}
	
	cin>>a>>b>>c>>d;
	
	if(a==b==c==d)
	r2=a*a;
	else
	{
		if(a!=b)
		r2=a*b;
		else if(a!=c)
		r2=a*c;
		else
		r2=a*d;
	}
	
	if(r1>r2)
	cout<<">";
	else if(r1<r2)
	cout<<"<";
	else if(r1==r2)
	cout<<"=";
	
	
}
