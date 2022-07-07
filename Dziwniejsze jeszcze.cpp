#include<iostream>
using namespace std;

int main()
{
	string s;
	int w=0, z=0;
	bool pal=true;
	
	cin>>s;
	
	for(int i=0; i<s.length(); i++)
	{		
		z=i;
		for(int j=0; j<=i; j++)
		{
			if(s[j]!=s[z])
			pal=false;
			
			z--;
		}
		
		if(pal==true)
		{
			w=i+1;	
		}
		
		pal=true;
	}
	
	cout<<w;
	
	return 0;
}
