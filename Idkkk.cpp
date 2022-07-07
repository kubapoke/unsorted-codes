#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	
	cin>>s;
	
	for(int i=0; i<s.length(); i++)
	{
		if(s[i]=='1')
		cout<<"pa";
		else if(s[i]=='2')
		cout<<"re";
		else if(s[i]=='3')
		cout<<"ci";
		else if(s[i]=='4')
		cout<<"vo";
		else if(s[i]=='5')
		cout<<"mu";
		else if(s[i]=='6')
		cout<<"xa";
		else if(s[i]=='7')
		cout<<"ze";
		else if(s[i]=='8')
		cout<<"bi";
		else if(s[i]=='9')
		cout<<"so";
		else if(s[i]=='0')
		cout<<"no";
	}
	
}
