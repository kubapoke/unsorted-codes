#include<bits/stdc++.h>
using namespace std;

int xp, yp, n, xa, ya, xb, yb, xf, yf;
bool wyn=true, kraw=false;

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>xp>>yp;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		xb=xa; yb=ya;
		cin>>xa>>ya;
		
		if(i==0)
		{
			xf=xa; yf=ya;
		}
		else
		{
			if((xb-xa)*(yp-ya)-(yb-ya)*(xp-xa)<0)
			wyn=false;
			
			else if((xb-xa)*(yp-ya)-(yb-ya)*(xp-xa)==0)
			{
				kraw=true;
				if(xp>max(xa,xb)||xp<min(xa,xb)||yp>max(ya,yb)||yp<min(ya,yb))
				wyn=false;
			}
		}
		
		if(i==n-1)
		{
			if((xa-xf)*(yp-yf)-(ya-yf)*(xp-xf)<0)
			wyn=false;
			
			else if((xa-xf)*(yp-yf)-(ya-yf)*(xp-xf)==0)
			{
				kraw=true;
				if(xp>max(xf,xa)||xp<min(xf,xa)||yp>max(yf,ya)||yp<min(yf,ya))
				wyn=false;
			}
			
		}
		
	}
	
	if(wyn==false)
	cout<<"NIE";
	else if(kraw==true)
	cout<<"KRAW";
	else
	cout<<"TAK";
}
