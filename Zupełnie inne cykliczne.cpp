#include<iostream>
using namespace std;

//wystêpuje tylko cykl

int main()
{
	string s;
	long long k, w=0;
	bool cykl=true;
	
	cin>>s>>k;
	
	for(int i=0; i<s.length()-k+1; i++)
	{
		if(s[i]==s[i+k])
		w++;
		else
		w=0;
		
		if(w==0)
		{
			cout<<"NIE";
			break;
		}
	}
	
	if(cykl==true)
	cout<<"TAK";
	else
	cout<<"NIE";
	
	return 0;
}
