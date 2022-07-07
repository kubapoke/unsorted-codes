#include<bits/stdc++.h>
using namespace std;

long long n, w=0, s=0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	
	if(n%2==1)
	w=(n+1)/2;
	else
	{
		w=n/2;
		while(n)
		{
			s+=n%2;
			n/=2;
		}
		if(s%2==1)
		w++;
	}
	
	cout<<w;
}
