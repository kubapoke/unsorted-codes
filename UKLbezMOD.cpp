#include<bits/stdc++.h>
using namespace std;

long long n, a, b, c=1, x, y, z=1, w, h, add1=1, add2=1, mn1, mn2;

int main()
{
	cin>>n;
	h=n-1;
	
	x=y=n*h;
	mn1=mn2=h;
	
	for(int i=0; i<=2*n-3; i++)
	{
		w+=(a+b)*c;
		
		a+=add1;
		if(add1!=h)
		add1++;
		
		b+=h;
		
		c*=mn1;
		if(mn1!=1)
		mn1--;
		
		if(i>=n)
		{
			w-=(x+y)*z;
			
			x+=add2;
			if(add2!=h)
			add2++;
			
			y+=h;
			
			z*=mn2;
			if(mn2!=1)
			mn2--;
		}
	}
	
	cout<<w/2;
}
