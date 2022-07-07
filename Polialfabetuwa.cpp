#include<iostream>
using namespace std;

int main()
{
	string s;
	int k, j;
	char c;
	
	cin>>s>>k;
	
	int tab[k];
	//int wyn[s];
	
	for(int i=0; i<k; i++)
	{
		cin>>tab[i];
	}
	
	for(int i=0; i<s.length(); i++)
	{
		j=i;
		
		while(j>=k)
		j=j-k;
		
		//while(tab[j]>=26)
		//tab[j]=tab[j]-26;
		
		c=s[i]+tab[j];
		
		if(c>122)
		c=c-26;
		
		
		cout<<c;
	}
	
	
	
	return 0;
}
