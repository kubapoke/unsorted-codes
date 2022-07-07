#include<bits/stdc++.h>
using namespace std;

string s;
string b;
queue<int> Apos;

int main()
{
	cin>>s;
	
	for(int i=0; i<s.size(); i++)
	{
		if(s[i]!='A')
		b.push_back(s[i]);
		else
		Apos.push(i);
	}
	
	sort(b.begin(),b.end());
	int ct=0;
	
	for(int i=0; i<b.size(); i++)
	{
		if(!Apos.empty())
		while(ct==Apos.front())
		{
			cout<<"A";
			Apos.pop();
			ct++;
		}
	
		cout<<b[i];
		ct++;
	}
	
	while(!Apos.empty())
	{
		cout<<"A";
		Apos.pop();
	}
}
