#include<iostream>
using namespace std;

int main()
{
	string s;
	int w=0;
	
	cin>>s;
	
	int lit[26];
	
	for(int i=0; i<26; i++)
	{
		lit[i]=0;
	}
	
	for(int i=0; i<s.length(); i++)
	{
		lit[s[i]-97]=1;
	}
	
	for(int i=0; i<26; i++)
	{
		if(lit[i]==1)
		w=w+1;
	}
	
	cout<<w;
	
	return 0;
}
