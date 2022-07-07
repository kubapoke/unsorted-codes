#include<iostream>
using namespace std;

int main()
{
	int a, b, w=0;
	char z;
	
	cin>>a>>b;
	
	w=a+b;
	z='+';
	
	if(a-b>w)
	{
		w=a-b;
		z='-';
	}
	else if(a-b==w)
	{
		cout<<"NIE";
		return 0;
	}
	
	if(a*b>w)
	{
		w=a*b;
		z='*';
	}
	else if(a*b==w)
	{
		cout<<"NIE";
		return 0;
	}
	
	if(a>=0&&b>=0)
	cout<<a<<z<<b<<"=";
	else if(a<0&&b>=0)
	cout<<"("<<a<<")"<<z<<b<<"=";
	else if(a>=0&&b<0)
	cout<<a<<z<<"("<<b<<")"<<"=";
	else if(a<0&&b<0)
	cout<<"("<<a<<")"<<z<<"("<<b<<")"<<"=";
	
	if(w>=0)
	cout<<w;
	else
	cout<<"("<<w<<")";
	
	return 0;
}
