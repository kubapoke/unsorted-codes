#include<bits/stdc++.h>
using namespace std;

int N;
string s, spop;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>N;
	
	for(int i=0; i<N; i++)
	{
		spop=s;
		cin>>s;
		
		if(s[1]=='B')
		s[1]='Z';
		
		if(i!=0)
		if(spop[0]>s[0])
		{
			cout<<"licytacja niepoprawna";
			return 0;
		}
		if(spop[0]==s[0]&&spop[1]>=s[1])
		{
			cout<<"licytacja niepoprawna";
			return 0;
		}
	}
	
	if(N%2==0)
	cout<<"WE";
	else
	cout<<"NS";
	
}
