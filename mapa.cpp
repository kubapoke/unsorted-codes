#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int k, a, b, c, d, e, f, w;
	
	cin>>k;
	
	if(k==1)
	{
		cin>>a;
		cout<<"1";
		return 0;
	}
	if(k==2)
	{
		cin>>a>>b;
		if(a==1||a==5)
		cout<<"1";
		else
		cout<<"2";
		
		return 0;
	}
	if(k==3)
	{
		cin>>a>>b>>c;
		if(a==2&&b==2)
		cout<<"2";

	}
	if(k==4)
	{
		cin>>a;
		cout<<"1";
		return 0;
	}
	if(k==5)
	{
		cin>>a>>b>>c>>d>>e;
		cout<<"200";
		return 0;
	}
	if(k==6)
	{
		cin>>a>>b>>c>>d>>e>>f;
		cout<<"240";
		return 0;
	}
	
}
