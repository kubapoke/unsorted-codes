#include<iostream>
using namespace std;

int main()
{
	string s;
	int a, k;
	char c;
	
	cin>>s>>k;
	
	int bruh[k];
	int tab[s.length()];
	
	for(int i=0; i<k; i++)
	{
		cin>>bruh[i];
	}
	
	for(int i=0; i<s.length(); i++)
	{	
		int j=i;
		
		while(j>=k)
		j=j-k;
	
		while(bruh[j])
		bruh[j]=bruh[j]-26;
		
		tab[i]=s[i]+bruh[j];
		
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
