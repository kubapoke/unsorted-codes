#include<iostream>
using namespace std;

int main()
{
	int k;
	string s;
	
	cin>>s>>k;
	
	if(s.length()%k!=0)
	{
		cout<<"NIE";
		return 0;
	}
	
	for(int i=0; i<k; i++)
	{
		if(s[i]!=s[i+k])
		{
			cout<<"NIE";
			return 0;
		}
	}
	
	cout<<"TAK";
	
	return 0;
}
