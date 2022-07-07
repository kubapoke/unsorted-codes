#include<bits/stdc++.h>
using namespace std;

int n, k, w=1, tab[1000001], wys[1000001];


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>k;
		
		w=max(w,tab[k]);
		
		if(wys[k]==0)
		for(int j=1; j*j<=k; j++)
		{
			if(k%j==0)
			{
				if(k/j<w)
				break;
				tab[j]=max(tab[j], k/j);
				tab[k/j]=max(tab[k/j], j);
			}
		}
		
		wys[k]++;
	}
	
	cout<<w;
}
