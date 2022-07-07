#include<bits/stdc++.h>
using namespace std;

string s, w;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>s;
	
	for(int i=0; i<s.size(); i++)
	{
		if(s[i]!='<')
		w.append(s,i,1);
		else if(w.size()>0)
		w.erase(w.size()-1,1);
	}
	
	cout<<w;
}
