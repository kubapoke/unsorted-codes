#include<bits/stdc++.h>
using namespace std;

long long n, m, a, b, c=1, x, y, z=1, w, mw, h, add1=1, add2=1, mn1, mn2;

int main()
{
	cin>>n>>m;
	h=n-1;
	
	x=y=n*h;
	mn1=mn2=h;
	
	for(int i=0; i<=2*n-3; i++)
	{
		if(i==2)
		c/=2;
		if(i<=1)
		{
			w+=((a+b)*c)/2;
			a+=add1;
			if(i<h-1)
			add1++;
			
			b+=h;
			
			c*=mn1;
			if(i<h-1)
			mn1--;
		}
		else
		{
			w=(w%m+(((a+b)%m)*c%m)%m)%m;
			a+=add1;
			if(i<h-1)
			add1++;
			
			b+=h;
			
			c=((c%m)*(mn1%m))%m;
			if(i<h-1)
			mn1--;
		}
		
		if(i>=n)
		{
			if(i==n+2)
			z/=2;
			if(i<=n+1)
			{
				mw+=((x+y)*z)/2;
			
				x+=add2;
				add2++;
				
				y+=h;
				
				z*=mn2;
				mn2--;
			}
			else
			{
				mw=(mw%m+(((x+y)%m)*z%m)%m)%m;
			
				x+=add2;
				add2++;
				
				y+=h;
				
				z=((z%m)*(mn2%m))%m;
				mn2--;
			}
		}
	}
	
	cout<<(w%m-mw%m+m)%m;
}
