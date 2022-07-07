#include<iostream>
#include<math.h>
#include <iomanip> 
using namespace std;
int main()
{
	const double d=0.00000001;
	
	long double p, a, x=0;
	
	cin>>p;
	
	s=0;
	a=p/4;
	k=p/2
	
	while(fabs(p/a-a)>d)
	{
		a+=p/a;
		a/=2;
		x++;
	}
	
	
	
	cout<<fixed<<setprecision(0)<<ceil(a);
	
}
