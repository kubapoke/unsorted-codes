#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int w=0;
	string s;
	
	cin>>s;
	
	int l=s.size();
	
	while(l>0)
	{
		w+=l;
		l--;	
	}
	
	cout<<w;
}
