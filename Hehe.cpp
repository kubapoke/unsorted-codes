#include<iostream>
using namespace std;

int main()
{
	int n;
	char c='-';
	string s;
	int lit[26];
	bool was=false;
	
	for(int i=0; i<26; i++)
	{
		lit[i]=0;
	}
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>s;
		
		for(int j=0; j<s.length()-1; j++)
		{
			if(s[j]==s[j+1])
			lit[s[j]-97]++;
		}
		
		for(int j=0; j<26; j++)
		{
			if(lit[j]>0)
			{
				c=j+97;
				cout<<c;
				was=true;
			}
		}
		
		if(was==false)
		cout<<"NULL";
		
		for(int j=0; j<26; j++)
		{
			lit[j]=0;
		}
		
		was=false;
		
		cout<<endl;
	}
	
	
	
	return 0;
}
