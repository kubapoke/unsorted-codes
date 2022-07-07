#include<bits/stdc++.h>
using namespace std;


int n, x, y;
int main()
{
	cin>>n;
	
	for(int i=1; i<=n; i++)
	{
		cin>>x>>y;
		
		if(x==0&&y==0)
		cout<<"00\n";
		else if(x==0)
		cout<<"0Y\n";
		else if(y==0)
		cout<<"0X\n";
		else if(x>0&&y>0)
		cout<<"Icw\n";
		else if(x<0&&y>0)
		cout<<"IIcw\n";
		else if(x<0&&y<0)
		cout<<"IIIcw\n";
		else if(x>0&&y<0)
		cout<<"IVcw\n";
	}
}
