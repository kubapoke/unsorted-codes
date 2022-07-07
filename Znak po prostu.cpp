#include<iostream>
using namespace std;

int main()
{
	char a, b;
	
	cin>>a>>b;
	
	if(a>=65 && a<=90)
	cout<<"W ";
	else if(a>=97 && a<=122)
	cout<<"M ";
	else if(a>=48 && a<=57)
	cout<<"C ";
	else
	cout<<"I ";
	
	if(b>=65 && b<=90)
	cout<<"W ";
	else if(b>=97 && b<=122)
	cout<<"M ";
	else if(b>=48 && b<=57)
	cout<<"C ";
	else
	cout<<"I ";
	
	return 0;
}
