#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long n, s=0,
	mn=1, z;
	string licz;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		s=0; mn=1;
		
		cin>>licz;
		
		z=licz.length()-1;
		
		for(int i=z; i>=0; i--)
		{
			if(licz[i]=='Y')
			s+=mn;
			else if(licz[i]=='<')
			s+=10*mn;
			else if(licz[i]==';')
			mn*=60;
			
		}
		
		cout<<s<<'\n';
	}
	
	return 0;
}
