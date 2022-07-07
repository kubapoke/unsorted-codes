#include<iostream>
using namespace std;

int main()
{
	int n;
	char c='-';
	string s;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>s;
		
		for(int j=0; j<s.length(); j++)
		{
			if(c!=s[j])
			{
				c=s[j];
				cout<<c;
			}
		
		}
		cout<<" ";
		c='-';	
	}
	
	return 0;
}
