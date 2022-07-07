#include<iostream>
using namespace std;

//cykl wystêpuje

int main()
{
	string s;
	int k, w=0;
	
	cin>>s>>k;
	
	for(int i=0; i<s.length(); i++)
	{
		if(s[i]==s[i+k])
		w++;
		else
		w=0;
		
		if(w==k)
		{
			cout<<"TAK";
			return 0;
		}
		
	}
	
	cout<<"NIE";
	
	return 0;
}
