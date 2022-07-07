#include<iostream>
using namespace std;

int main()
{
	string s;
	int a;
	char c;
	
	cin>>s;
	
	int tab[s.length()];
	
	for(int i=0; i<s.length(); i++)
	{
		cin>>a;
		
		while(a>=26)
		a=a-26;
		
		tab[i]=s[i]+a;
		
		if(tab[i]>122)
		tab[i]=tab[i]-26;
	}
	
	for(int i=0; i<s.length(); i++)
	{
		c=tab[i];
		cout<<c;
	}
	
	return 0;
}
