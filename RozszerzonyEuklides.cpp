#include<iostream>
using namespace std;

int x, y;
void euklides(int a, int b)
{
	if(b!=0)
	{
		euklides(b, a%b);
		swap(x-=a/b*y,y);
	}
}
int main()
{
	x = 1, y = 0;
	int a, b;
	
	cout<<"Podaj liczby: ";
	cin>>a>>b;
	
	euklides(a, b);
	
	cout<<"nwd("<<a<<", "<<b<<") = "
	<<a<<" * "<<x<<" + "<<b<<" * "<<y<<" = "
	<<a*x+b*y<<endl;
	
	return 0;
}
