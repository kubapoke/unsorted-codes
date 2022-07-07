#include<iostream>
using namespace std;

int main()
{
	int n, start=0, x=0;
	string s;
	
	cin>>s>>n;
	
	while(1)
	{
		cout<<s[x];
		
		if(x+n<s.length())
		{
			x+=n;
		}
		else
		{
			start++;
			x=start;
		}
			
		if(start>=n)
		return 0;		
	}
}
