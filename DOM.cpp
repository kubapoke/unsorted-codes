#include<bits/stdc++.h>
using namespace std;

long long n, w=0, d=0, fib[87];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	
	fib[1]=1; fib[2]=2;
	
	for(int i=3; i<87; i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
	}
	
	for(int i=86; i>=2; i--)
	{
		while(n%fib[i]==0)
		{
			n/=fib[i];
			w+=i;
			d++;
		}
	}
	
	w+=d-1;
	
	//if(n==1)
	cout<<w;
	//else
	//cout<<"NIE";
}
