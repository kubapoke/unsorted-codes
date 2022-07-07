#include<iostream>
using namespace std;

//wystêpuje tylko cykl

int main()
{
	string s;
	long long k, w=0;
	bool cykl=true;
	
	cin>>s>>k;
	
	int d=k;
	
	if(s.length()%2!=0)
	d--;
	
	for(int i=0; i<s.length()-d; i++)
	{
		//if(s[i]==s[i+k])
		//w++;
		//else
		//w=0;
		
		if(s[i]!=s[i+k])
		{
			cout<<"NIE";
			return 0;
		}
	}
	
	//if(cykl==true)
	cout<<"TAK";
	//else
	//cout<<"NIE";
	
	return 0;
}
