#include<iostream>
using namespace std;

int main()
{
	int a;
	
	cin>>a;
	
	if(a%3==0 && a%5==0)
	cout<<"Fizz Buzz";
	else if(a%3==0)
	cout<<"Fizz";
	else if(a%5==0)
	cout<<"Buzz";
	else
	cout<<a;
	
	return 0;
}
