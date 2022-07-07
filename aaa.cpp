#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	const float a=20;
	float i=10, x;
	int w=0;
	
	while(i<100)
	{
		x=a*i;
		
		cout<<sqrt(x)<<'\n';
		
		i++;	
	}
	
}
