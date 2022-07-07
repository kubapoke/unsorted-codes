#include<bits/stdc++.h>
using namespace std;
int n, xa ,ya, xb, yb, xc, yc;

int main()
{
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>xa>>ya>>xb>>yb>>xc>>yc;
		
		int S=abs((xb-xa)*(yc-ya)-(yb-ya)*(xc-xa));
		
		if(S==0)
		cout<<"TAK\n";
		else
		cout<<"NIE\n";
	}
}
