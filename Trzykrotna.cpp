#include<iostream>
using namespace std;

//wyst�puje tylko cykl

int main()
{
	string a, b;
	
	cin>>a>>b;
	
	if(b.length()/3>=a.length())
	cout<<"JEST";
	else
	cout<<"NIE";
	
	return 0;
}
