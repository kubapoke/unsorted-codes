#include<iostream>
using namespace std;

int main()
{
	string s, t;
	bool czy=true;
	
	cin>>s>>t;
	
	for(int i=0; i<t.length(); i++)
	{
		if(s[i]!=t[i])
		czy=false;
	}
	
	if(czy==true)
	cout<<"TAK";
	else
	cout<<"NIE";
	
	return 0;
}
