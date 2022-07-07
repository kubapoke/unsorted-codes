#include<bits/stdc++.h>
using namespace std;

int a, b, r, n, x, y;
float odl;

int main()
{
	cin>>a>>b>>r>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>x>>y;
		
		odl=sqrt(pow((float)abs(x-a),2)+pow((float)abs(y-b),2));
		
		if(odl<r)
		cout<<"W\n";
		else if(odl==r)
		cout<<"O\n";
		else
		cout<<"Z\n";
	}
}
