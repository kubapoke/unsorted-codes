#include<bits/stdc++.h>
using namespace std;

int countz, counto, w;

int main()
{
	for(int i=0; i<1000; i++)
	{
		countz=0; counto=0;
		string s;
		cin>>s;
		for(int j=0; j<s.size(); j++)
		{
			if(s[j]=='0')
			countz++;
			else if(s[j]=='1')
			counto++;
		}
		if(countz>counto)
		w++;
	}
	cout<<w;
}
