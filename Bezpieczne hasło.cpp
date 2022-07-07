#include<iostream>
using namespace std;

int main()
{
	bool dlug=false, wiel=false, mal=false, cyf=false, znak=false;
	string s;
	
	cin>>s;
	
	if(s.length()>=13)
	dlug=true;
	else
	{
		cout<<"NIE";
		return 0;
	}
	
	for(int i=0; i<s.length(); i++)
	{
		if(s[i]>=65&&s[i]<=90)
		wiel=true;
		else if(s[i]>=97&&s[i]<=122)
		mal=true;
		else if(s[i]>=48&&s[i]<=57)
		cyf=true;
		else if(s[i]=='!'||s[i]=='@'||s[i]=='#'||s[i]=='$'||s[i]=='%'||s[i]=='^'||s[i]=='&'||s[i]=='*')
		znak=true;
	}
	
	if(dlug==true&&wiel==true&&mal==true&&cyf==true&&znak==true)
	cout<<"BEZPIECZNE";
	else 
	cout<<"NIE";
	
	
	return 0;
}
