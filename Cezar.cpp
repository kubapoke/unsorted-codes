#include<iostream>
using namespace std;

int main()
{
	string s;
	int k;
	char c;
	
	cin>>s>>k;
	
	while(k>=26)
	k=k-26;
	
	for(int i; i<s.length(); i++)
	{
		if(s[i]+k<123)
		{
			c=s[i]+k;
			cout<<c;
		}
		else
		{
			c=s[i]+k-26;
			cout<<c;
		}
	}
	
	return 0;
}
