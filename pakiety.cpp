#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio;
	cin.tie(0);
	
	register int n, a, s=0, najw=0;
	bool czy=true;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		
		cin>>a;
		
		if(a<najw)
		s+=a;
		else
		{
			s+=najw;
			najw=a;
		}
	}
	
	if(najw>s)
	czy=false;
	
	
	s+=najw;
	
	if(s%2==0 && czy==true)
	cout<<"NIE";
	else
	cout<<"TAK";
	
	
	
	
	
	return 0;
}
