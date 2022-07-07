#include<bits/stdc++.h>
using namespace std;

int p1, p2;
string s1, s2;

int main()
{
	for(int i=0; i<255; i++)
	s2.append("0");
	
	for(int i=0; i<1000; i++)
	{
		string s;
		cin>>s;
		
		if(s.size()>s1.size())
		{
			s1=s;
			p1=i+1;
		}
		else if(s.size()==s1.size())
		{
			for(int j=0; j<s.size(); j++)
			{
				if(s[j]=='0'&&s1[j]=='1')
				break;
				else if(s[j]=='1'&&s1[j]=='0')
				{
					s1=s;
					p1=i+1;
				}
			}
		}
		
		if(s.size()<s2.size())
		{
			s2=s;
			p2=i+1;
		}
		else if(s.size()==s2.size())
		{
			for(int j=0; j<s.size(); j++)
			{
				if(s[j]=='1'&&s2[j]=='0')
				break;
				else if(s[j]=='0'&&s2[j]=='1')
				{
					s2=s;
					p2=i+1;
				}
			}
		}
	}
	cout<<p2<<"\n"<<p1;
}
