#include<iostream>
using namespace std;

int main()
{
	string a, b;
	int w=0, c=0;
	cin>>a;
	
	for(int i=0; i<5; i++)
	{
		cin>>b;
		
		for(int j=0; j<b.length(); j++)
		{
			if(a[c]==b[j])
			c++;
			else
			c=0;
			if(c==a.length())
			w++;
		}
		
		c=0;
		
		
	}
	
	cout<<w;
	
	return 0;
}
