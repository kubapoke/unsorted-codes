#include<bits/stdc++.h>
using namespace std;

int n, a, b, d[200001], ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	for(int i=1; i<=n; i++)
	{
		cin>>d[i];
	}
	
	sort(d+1,d+n+1);
	
	ans=d[n]-d[1];
	
	for(int i=2; i<=n; i++)
	ans=min(ans, d[n]-d[1]-(d[i]-d[i-1]));
	
	cout<<ans;
}
