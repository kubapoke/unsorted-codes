#include<bits/stdc++.h>
using namespace std;

int n, xa, ya, ra, xb, yb, rb;
double odl, pok;

int main()
{
	cin>>n;
	
	for(int i=1; i<=n; i++)
	{
		cin>>xa>>ya>>ra>>xb>>yb>>rb;
		
		odl=sqrt(pow(xa-xb,2)+pow(ya-yb,2));
		
		if(odl==0&&ra==rb)
		pok=2*ra;
		else if(odl==abs(ra-rb))
		pok=2*(min(ra,rb));
		else if(odl==ra+rb)
		pok=0;
		else if(odl<abs(ra-rb))
		pok=2*(min(ra,rb));
		else if(odl>ra+rb)
		pok=0;
		else
		pok=ra+rb-odl;
		cout<<fixed<<setprecision(2)<<pok<<"\n";
	}
}
