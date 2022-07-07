#include<bits/stdc++.h>
using namespace std;

int n, tab[100001], ilea[100001], tempa[100001], K1, K2, ans, roz;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>tab[i];
		ilea[tab[i]]++;
		if(ilea[tab[i]]==1)
		roz++;
	}
	
	K1=0; K2=roz;
	ans=roz;
	
	for(int i=0; i<n; i++)
	{
		tempa[tab[i]]++;
		ilea[tab[i]]--;
		
		if(tempa[tab[i]]==1)
		K2--;
		if(ilea[tab[i]]==0)
		K1++;
		
		ans=min(ans,K1+K2);
	}
	
	cout<<ans;
}
