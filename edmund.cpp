#include<bits/stdc++.h>
using namespace std;

//oi!(IZ!ys

string s;
int main()
{
	cin>>s;
	
	for(int y=1; y<=255; y++)
	{
		for(int i=0; i<s.size(); i++)
		{
			s[i]-=y;
			while(s[i]<0)
			s[i]=255-s[i]+1;
			if(s[i]>255)
			s[i]%=255;
			cout<<s[i];
			s[i]+=y;
		}
		cout<<"\n";
		
		for(int i=0; i<s.size(); i++)
		{
			s[i]+=y;
			while(s[i]<0)
			s[i]=255-s[i]+1;
			if(s[i]>255)
			s[i]%=255;
			cout<<s[i];
			s[i]-=y;
		}
		cout<<"\n";
	}
}
