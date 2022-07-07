#include<iostream>
#include<cmath>
#include<math.h>
#include<iomanip>

using namespace std;

int main()
{
	register long double a;
	
	cin>>a;
	
	cout<<fixed<<setprecision(0)<<ceil(sqrt(a));
	
	
	return 0;
}
