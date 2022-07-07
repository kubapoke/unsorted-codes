#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
int n, k, ans=1e9, ca, cb, f, b;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>k>>s;
	
	for(int i=0; i<k; i++)
	{
		b=i;
		if(s[b]=='A')
		ca++;
		else
		cb++;
	}
	
	ans=abs(ca-cb);
	
	for(int i=k; i<n; i++)
	{
		b=i;
		f=i-k;
		if(s[b]=='A')
		ca++;
		else
		cb++;
		if(s[f]=='A')
		ca--;
		else
		cb--;
		
		ans=min(ans,abs(ca-cb));
	}
	
	cout<<ans;
}
