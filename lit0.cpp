#include<bits/stdc++.h>
using namespace std;

string a, b;
int ile[26], w;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>a>>b;
	
	for(int i=0; i<a.size(); i++)
	{
		if(a[i]!=b[i])
		{
			ile[a[i]-'a']++; ile[b[i]-'a']++;
		}
	}
	
	for(int i=0; i<26; i++)
	if(ile[i]>0)
	w++;
	w--;
	
	cout<<max(w,0);
}
