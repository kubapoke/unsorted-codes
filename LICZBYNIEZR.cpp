#include<bits/stdc++.h>
using namespace std;

long long N, pt, pos, ans;

int main()
{
	cin>>N;
	
	pt=N/5;
	
	if(N%5==0)
	pt--;
	
	pos=N%5;
	
	ans+=8*pt;
	
	if(pos==1)
	cout<<ans+1;
	if(pos==2)
	cout<<ans+3;
	if(pos==3)
	cout<<ans+5;
	if(pos==4)
	cout<<ans+7;
	if(pos==0)
	cout<<ans+8;
}
