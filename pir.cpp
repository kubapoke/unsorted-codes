#include<bits/stdc++.h>
using namespace std; 

int n, wys[50001], maxl[50001], maxr[50001], w;

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>n;
	
	for(int i=1; i<=n; i++)
	cin>>wys[i];
	
	for(int i=1; i<=n; i++)
	{
		maxl[i]=min(i, min(maxl[i-1]+1, wys[i]));
	}
	
	for(int i=n; i>=1; i--)
	{
		if(i==n)
		{
			if(wys[i]>0)
			maxr[i]=1;
			else
			maxr[i]=0;
		}
		else
		maxr[i]=min(n-i+1, min(maxr[i+1]+1, wys[i]));
	}
	
	for(int i=1; i<=n; i++)
	w=max(w,min(maxl[i],maxr[i]));
	
	cout<<w;
	
}
