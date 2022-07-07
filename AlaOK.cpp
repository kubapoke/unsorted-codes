#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans;

bool check(int a,int b,int c,int d,int e,int f)
{
	int arr[6]={0,0,0,0,0,0};
	arr[a]++; arr[b]++; arr[c]++; arr[d]++; arr[e]++; arr[f]++; 
	
	for(int i=1; i<6; i++)
	{
		if(arr[i] && !arr[i-1])
		return false;
	}
	
	return true;
}

int main()
{
	for(int a=0; a<6; a++)
	for(int b=0; b<6; b++)
	for(int c=0; c<6; c++)
	for(int d=0; d<6; d++)
	for(int e=0; e<6; e++)
	for(int f=0; f<6; f++)
	if(a<b && check(a,b,c,d,e,f))
	{
		ans++;
		cout<<"a"<<a<<" "<<"b"<<b<<" "<<"c"<<c<<" "<<"d"<<d<<" "<<"e"<<e<<" "<<"f"<<f<<"\n";
	}
	
	cout<<ans;
}

