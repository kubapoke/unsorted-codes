#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

string s;
int ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>s;
	int n=s.size();
	
	for(int a=0; a<n; a++)
	for(int b=a+1; b<n; b++)
	for(int c=b+1; c<n; c++)
	for(int d=c+1; d<n; d++)
	for(int e=d+1; e<n; e++)
	for(int f=e+1; f<n; f++)
	{
		if(s[c]==s[e] && s[d]==s[f] && s[c]!=s[d] && s[a]!=s[b] && s[a]!=s[c] && s[a]!=s[d] && s[b]!=s[c] && s[b]!=s[d])
		{
			ans++;
			ans%=mod;
		}
	}
	
	cout<<ans;
}
