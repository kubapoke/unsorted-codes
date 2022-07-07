#include<iostream>
using namespace std;

int main()
{
	string s;
	int k;
	int c=0;
	
	cin>>s>>k;
	
	for(int i=0; i<k; i++)
	{
		c=i;
		while(c<s.length())
		{
			cout<<s[c];
			c=c+k;
		}
	}
	
	return 0;
}
