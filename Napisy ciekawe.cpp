#include<iostream>
using namespace std;

int main()
{
	int k, a=0, w=0, c=0;
	string s;
	
	cin>>k;
	
	for(int i=0; i<k; i++)
	{
		cin>>s;
		
		for(int j=0; j<s.length(); j++)
		{
			a=a+s[j];
		}
		
		for(int j=1; j*j<=a; j++)
		{
			if(a%j==0)
			c++;
		}
		
		if(c<=1)
		w++;
		
		a=0; c=0;
	}
	
	cout<<w;
	
	return 0;
}
