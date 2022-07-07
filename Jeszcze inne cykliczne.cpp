#include<iostream>
using namespace std;

//

int main()
{
	string s;
	long long k, w=0;
	bool cykl=false;
	
	cin>>s>>k;
	
	for(int i=0; i<s.length()-k+1; i++)
	{
		if(s[i]==s[i+k])
		w++;
		else
		w=0;
		
		if(w==k)
		{
			cykl=true;
			break;
		}
		
	}
	
	if(cykl==true)
	cout<<"TAK";
	else
	cout<<"NIE";
	
	return 0;
}
