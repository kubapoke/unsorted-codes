#include<bits/stdc++.h>
using namespace std;

long double n, xa, xb, ya, yb, xf, yf, w;

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		if(i>0&&xb==xa&&yb==ya)
		{
			cout<<"BLAD";
			return 0;
		}
		
		xb=xa; yb=ya;
		
		cin>>xa>>ya;
		
		if(i==0)
		{
			xf=xa; yf=ya;
		}
		
		if(i>0)
		{
			w+=abs( xb*ya-yb*xa );
		}
	}
	
	w+=abs( xf*ya-yf*xa );
	
	w/=2;
	
	cout<<floor(w);
}
