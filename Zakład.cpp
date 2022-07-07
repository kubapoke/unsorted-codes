#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	register int n, k, roz=0, a, w=0;
	int kostki[6];
	
	for(int i=0; i<6; i++)
	kostki[i]=0;
	
	cin>>n>>k;
	
	for(int i=0; i<n; i++)
	{
		cin>>a;
		
		if(kostki[a-1]==0)
		roz++;
		
		kostki[a-1]++;
	}
	
	if(roz==k)
	{
		cout<<"0";
		return 0;
	}
	
	if(roz<k)
	{
		cout<<k-roz;
		return 0;
	}
	
	if(roz>k)
	{
		sort(kostki, kostki+6);
		
		for(int i=0; i<roz-k; i++)
		{
			w+=kostki[i];	
		}
		
		cout<<w;
		return 0;
	}
	
}
