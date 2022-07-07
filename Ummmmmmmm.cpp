#include<iostream>
using namespace std;

int main()
{
	string s, x;
	int w=0, c=0;
	bool sth=false;
	
	cin>>s;
	
	for(int i=0; i<5; i++)
	{
		cin>>x;
		
		for(int j=0; j<x.length(); j++)
		{
			if(sth==false)
			{
				if(x[j]==s[c])
				c++;
				else
				c=0;
				
				if(c==s.length())
				{
					w++;
					sth=true;
				}
			}		
			c=0;
			sth=false;
		}
	}
	
	
	cout<<w;
	
	return 0;
}
