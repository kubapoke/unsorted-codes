#include<iostream>
using namespace std;

int main()
{
	string a, b;
	
	bool W1=false, W2=false, M1=false, M2=false, C1=false, C2=false;
	
	cin>>a>>b;
	
	for(int i=0; i<a.length(); i++)
	{
		if(a[i]>64&&a[i]<91)
		W1=true;
		
		if(a[i]>96&&a[i]<123)
		M1=true;
		
		if(a[i]>47&&a[i]<58)
		C1=true;
	}
	
	for(int i=0; i<b.length(); i++)
	{
		if(b[i]>64&&b[i]<91)
		W2=true;
		
		if(b[i]>96&&b[i]<123)
		M2=true;
		
		if(b[i]>47&&b[i]<58)
		C2=true;
	}
	
	if(W1==W2&&M1==M2&&C1==C2)
	cout<<"TAK";
	else
	cout<<"NIE";
	
	
	return 0;
}
