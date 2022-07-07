#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, a, b, ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	cin>>a;
	
	for(int i=1; i<n; i++)
	{
		b=a;
		cin>>a;
		ans=max(ans,abs(a-b));
	}
	
	cout<<ans;
}
