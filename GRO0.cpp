#include<bits/stdc++.h>
using namespace std;

string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>s;
	
	if(s.size()==1)
	{
		cout<<"NIE";
		return 0;
	}
	
	for(int i=0; i<s.size()-1-i; i++)
	{
		if(s[i]!=s[s.size()-1-i])
		{
			cout<<1;
			return 0;
		}
	}
	
	if(s.size()%2==1)
	for(int i=2; i<s.size(); i++)
	{
		if(s[i]!=s[i-2])
		break;
		
		if(i==s.size()-1)
		{
			cout<<"NIE";
			return 0;
		}
	}
	
	for(int i=1; i<s.size()-1-i; i++)
	{
		if(s[i]!=s[i-1])
		{
			cout<<2;
			return 0;
		}
	}
	
	cout<<"NIE";
}
