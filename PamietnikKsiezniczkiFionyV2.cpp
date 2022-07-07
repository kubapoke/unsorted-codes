#include<bits/stdc++.h>
using namespace std;

string a, b;
set<int> dod[26];
int odp[10000000], ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>a>>b;
	
	ans=a.size();
	
	int g=0;
	for(int i=a.size()-1; i>=0; i--)
	{
		dod[a[i]-'a'].insert(g);
		g++;
	}
	
	for(int i=0; i<b.size(); i++)
	{
		for(auto u: dod[b[i]-'a'])
		{
			if(i+u>b.size())
			break;
			odp[i+u]++;
		}
		
		ans=min(ans, (int)a.size()-odp[i]);
	}
	
	cout<<ans;
}
