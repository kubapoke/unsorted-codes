#include<bits/stdc++.h>
using namespace std;

bool a, b, c, d;
	string s;

int main()
{
	cin>>s;
	
	for(int i=0; i<s.size(); i++)
	{
		if(s[i]>='A'&&s[i]<='Z')
		a=true;
		
		if(s[i]>='a'&&s[i]<='z')
		b=true;
		
		if(s[i]>='0'&&s[i]<='9')
		c=true;
		
		if(s[i]=='@'||s[i]=='$'||s[i]=='#'||s[i]=='*')
		d=true;
	}
	
	if(a&&b&&c&&d&&s.size()>=8)
	cout<<"TAK";
	else
	cout<<"NIE";
}
