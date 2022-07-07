#include<bits/stdc++.h>
using namespace std;

int n, roz, ans; 
string s;

long double tab[1000001], mini;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>s;
	
	for(int i=0; i<n; i++)
	{
		if(s[i]=='G')
		tab[i+1]=tab[i]+1;
		else if(s[i]=='D')
		tab[i+1]=tab[i]-1;
		
		mini=min(mini,tab[i]);
	}
	
	for(int i=0; i<=n; i++)
	{
		tab[i]+=abs(mini);
	}
	
	for(int i=1; i<n; i++)
	{
		long double nach = (tab[i]-tab[0])/(long double)i;
		
		//cout<<nach<<" "<<(tab[n]+ans-tab[0])/(long double)n<<"\n";
		
		while(nach >= (tab[n]+(long double)ans-tab[0])/(long double)n)
		{
			ans+=1;
		}
		
		//<<(nach-(tab[n]+ans-tab[0])/(long double)n)<<"\n";
	}
	
	cout<<ans;
}
