#include<iostream>
using namespace std;

int main()
{
	string s;
	int w=0, z=0;
	
	cin>>s;
	
	for(int i=0; i<s.length(); i++)
	{		
		z=i;
		for(int j=0; j<=i; j++)
		{
			if(s[j]==s[z])
			w=i+1;
			else
			break;
			
			z--;
		}
	}
	
	cout<<w;
	
	return 0;
}
