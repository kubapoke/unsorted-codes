#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int suma=0;
	string s;
	bool przezdwa=true, przeztrzy=true;
	
	cin>>s;
	
	for(int i=0; i<s.length(); i++)
	{
		suma+=(s[i]-48);
	}
	
	if(suma%3!=0)
	{
		przeztrzy=false;
	}
	
	if(s[s.length()-1]%2!=0)
	{
		przezdwa=false;
	}
	
	if(przezdwa==true&&przeztrzy==true)
	cout<<"TAK";
	else
	cout<<"NIE";
	
}
