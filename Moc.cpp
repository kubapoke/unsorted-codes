#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	double a, b, c, d;
	const int x=1000000007;
	
	cin>>a>>b>>c>>d;
	
	cout<<(((a%x*b%x)%x)*((pow(c, -1)%x*pow(d, -1))%x))%x;
}
