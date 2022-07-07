#include<iostream>
using namespace std;

int main()
{
	string s;
	int a;
	char c;
	
	cin>>s;
	
	for(int i=0; i<s.length(); i++)
	{
		cin>>a;
		
		while(a>=26)
		a=a-26;
	
		
		s[i]=s[i]+a;
		if(s[i]>122)
		{
			c=s[i]-26;
			cout<<c;
		}
		else
		{
			c=s[i];
			cout<<c;
		}
	}
	
	return 0;
}
