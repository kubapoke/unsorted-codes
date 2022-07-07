#include<bits/stdc++.h>
using namespace std;

long long n, a[100001], b[100001], sval, ans;

long long check(int i)
{
	if(b[i]==0)
	return sval;
	
	long long mn=sval/b[i];
	
	if(abs(sval-b[i]*mn)>abs(sval-b[i]*(mn+1)))
	mn++;
	else if(abs(sval-b[i]*mn)>abs(sval-b[i]*(mn-1)))
	mn--;
	
	if(sval*b[i]>=0)
	mn=min(mn,a[i]);
	
	return sval-b[i]*mn;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	for(int i=1; i<=n; i++)
	cin>>a[i];
	
	for(int i=1; i<=n; i++)
	{
		cin>>b[i];
		sval+=a[i]*b[i];
	}
	
	ans=abs(sval);
	
	for(int i=1; i<=n; i++)
	if(abs(ans)>abs(check(i)))
	ans=check(i);
	
	cout<<abs(ans);
}
