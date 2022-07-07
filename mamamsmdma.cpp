#include<iostream>
#include<cstdlib>
#include<iomanip> 
#include<math.h>
using namespace std;

int main()
{
	long long a,b,c,d,ab,cd;
	double abcd;
	const long long z=1000000007;
	
	cin>>a>>b>>c>>d;
	
	a%=z;
	b%=z;
	c%=z;
	d%=z;
	
	ab=a*b;
	ab%=z;
	
	cd=c*d;
	cd%=z;
	
	abcd=double(ab)/double(cd);
	
	if(abcd<1)
	cout<<fixed<<setprecision(0)<<ceil(abcd*z);
	else
	cout<<fixed<<setprecision(0)<<ceil(abcd);
	
	
}
