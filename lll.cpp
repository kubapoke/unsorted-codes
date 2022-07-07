#include<bits/stdc++.h>
using namespace std;

int NWD(int xa, int ya, int xb, int yb)
{	
	int a=abs(xa-xb);
	int b=abs(ya-yb);
	int t;
	
	while(b!=0)
	{
		t=b;
		b=a%b;
		a=t;
	}
	
	 return a;
}

int n, xa, ya, xb, yb, xc, yc;

int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	
	for(int i=1; i<=n; i++)
	{
		cin>>xa>>ya>>xb>>yb>>xc>>yc;
		
		int sum=NWD(xa,ya,xb,yb)+NWD(xa,ya,xc,yc)+NWD(xc,yc,xb,yb);
		
		
		int P=abs(((xb-xa)*(yc-ya)-(yb-ya)*(xc-xa)));
		
		//cout<<sum<<" "<<P<<"\n";
		
		cout<<(P-sum+2)/2<<"\n";
	}
}
