#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n, max=0;
	
	int male[26], duze[26];
	
	for(int i=0; i<26; i++)
	{
		male[i]=0;
		duze[i]=0;
	}
	
	string s;
	
	char c;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		getline(cin, s);
		
		for(int j=0; j<s.length(); j++)
		{
			if(64<s[j]<91)
			{
				duze[j]++;
			}
			else if(96<s[j]<123)
			{
				male[j]++;
			}
		}
	}
	
	for(int i=0; i<26; i++)
	{
		if(male[i]>0)
		{
			c=i+65;
			cout<<c<<" "<<male[i]<<'\n';
		}
		
	}
	for(int i=0; i<26; i++)
	{
		if(duze[i]>0)
		{
			c=i+97;
			cout<<c<<" "<<male[i]<<'\n';
		}
		
	}
}
