#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int ilej=0, ilez=0, w=0, mn=1;
	string s;
	
	cin>>s;
	
	for(int i=0; i<s.length(); i++)
	{
		if(s[i]=='j')
		ilej++;
		if(s[i]=='z')
		ilez++;
	}
	
	for(int i=0; i<ilej; i++)
	cout<<"1";
	for(int i=0; i<ilez; i++)
	cout<<"0";
	
	cout<<" ";
	
	while(ilej>0)
	{
		while(ilez>0)
		{
			ilez--;
			mn*=2;
		}
		w+=mn;
		mn*=2;
		ilej--;
	}
	
	cout<<w;
}
