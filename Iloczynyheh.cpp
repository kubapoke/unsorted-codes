#include<iostream>
using namespace std;

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	register int n, k, a, najw=-1001, dnajw=-1001, tnajw=-1001, najm=1001, dnajm=1001, x, y;
	
	cin>>k;
	
	for(int j=0; j<k; j++)
	{
		najw=-1001; dnajw=-1001; tnajw=-1001; najm=1001; dnajm=1001;
		
		cin>>n;
		
		for(int i=0; i<n; i++)
		{
			cin>>a;
			
			if(a>=najw)
			{
				tnajw=dnajw;
				dnajw=najw;
				najw=a;
			}
			else if(a>=dnajw)
			{
				tnajw=dnajw;
				dnajw=a;
			}
			else if(a>tnajw)
			tnajw=a;
			
			if(a<=najm)
			{
				dnajm=najm;
				najm=a;
			}
			else if(a<dnajm)
			dnajm=a;
		}
		
		x=najw*dnajw*tnajw;
		y=najw*najm*dnajm;
	
		if(n<5 || x>y)
		cout<<x<<"\n";
		else
		cout<<y<<"\n";
	}
	
}
