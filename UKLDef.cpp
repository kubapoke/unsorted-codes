#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

ll n, w, sumr, suml;
ld ava; //average/addition
int m;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	
	ava=(ld)n/2;
	
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	if(n==2)
	{
		cout<<1;
		return 0;
	}
	
	for(int i=0; i<n; i++)
	{
		sumr=(ll)((ld)suml+ava)*(ld)(n-1);
		w=(w%m+sumr%m)%m;
		suml=sumr-
	}
}
