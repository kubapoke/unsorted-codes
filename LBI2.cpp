#include<bits/stdc++.h>
using namespace std;

int w1, w2;

int main()
{
	for(int i=0; i<1000; i++)
	{
		string s;
		cin>>s;
		int l=s.size();
		
		if(l>1)
		if(s[l-1]=='0')
		w1++;
		
		if(l>3)
		if(s[l-1]=='0'&&s[l-2]=='0'&&s[l-3]=='0')
		w2++;
	}
	cout<<w1<<"\n"<<w2;
}
