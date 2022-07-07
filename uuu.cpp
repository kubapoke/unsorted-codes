#include<bits/stdc++.h>
using namespace std;
int n, xa ,ya, xb, yb, xc, yc, xd, yd;

int main()
{
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>xa>>ya>>xb>>yb>>xc>>yc>>xd>>yd;
		
		int S1=abs((xa-xc)*(yb-yc)-(ya-yc)*(xb-xc));
		int S2=abs((xa-xd)*(yc-yd)-(ya-yd)*(xc-xd));
		int S3=abs((xa-xb)*(yd-yb)-(ya-yb)*(xd-xb));
		
		int S4=abs((xb-xd)*(yc-yd)-(yb-yd)*(xc-xd));
		
		if(S1+S2+S3==S4) cout<<"TAK\n"; else cout<<"NIE\n";
	}
}
