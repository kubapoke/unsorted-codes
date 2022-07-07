#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n, b, x=0, y=1, s=0, g=2;
	
	cin>>n;
	
	
	for(float i=1; i<=n; i+=1)
	{
		cin>>b;
		s+=b;
		
		if(float(s)/float(i)>float(x)/float(y))
		{
			x=s;
			y=i;
		}
	}
	
	g=y;
	
	while(g>1)
	{
		while(x%g==0 && y%g==0)
		{
			x/=g;
			y/=g;
		}
		
		g--;
	}
	
	cout<<x<<"/"<<y;
	
}
