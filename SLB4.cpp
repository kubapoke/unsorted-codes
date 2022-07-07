#include<bits/stdc++.h>
using namespace std;

string s;
long long w=0, mn=1;

int main()
{
	for(int i=0; i<999; i++)
	{
		cin>>s;
		if(s[s.size()-1]=='8')
		{
			mn=1;
			for(int i=s.size()-2; i>=0; i--)
			{
				w+=(s[i]-48)*mn;
				mn*=8;
			}
		}
	}
	cout<<w;
}
