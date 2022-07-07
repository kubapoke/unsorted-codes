#include<iostream>
using namespace std;

int main()
{
	int k, l=0, w=0;
	string s;
	
	cin>>k;
	
	for(int i=0; i<k; i++)
	{
		cin>>s;
		
		for(int j=0; j<s.length(); j++)
		{
			l=l+s[j]-48;
		}
		
		if(l%3==0)
		w++;
		
		l=0;
	}
	
	cout<<w;
	
	return 0;
}
