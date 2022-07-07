#include<bits/stdc++.h>
using namespace std;

/*
3
5 1
1 3 6 10 15
5 2
1 3 6 10 15
6 2
1 5 7 11 14 17
*/

int t, n, k, a, b, ans=1e9;
vector<int> koszt;

void spr(int p, int w, int g)//pozycja, wynik, mozliwoœæ przesuniêcia
{	
	//cout<<p<<" "<<n-2-(2*(k-g))<<" "<<k<<" "<<g<<" \n";
	//cout<<ans<<" a  ";
	//cout<<koszt[p]<<" k  ";
	w+=koszt[p];
	//cout<<w<<" c  ";
	
	if(k==g)
	ans=min(ans,w);	
	
	
	while(p<=n-1-(2*(k-g)))
	{
		
		//cout<<ans<<" b  ";
		if(k!=g)
		for(int i=2; p+i<=n-1-(2*(k-(g+1))); i++)
		spr(p+i,w, g+1);
		
		w-=koszt[p];
		//cout<<w<<" d  ";
		p++;
		w+=koszt[p];
		//cout<<w<<" e  ";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>t;
	
	for(int te=1; te<=t; te++)
	{
		ans=1e9;
		
		koszt.clear();
		
		cin>>n>>k;
		
		for(int i=1; i<=n; i++)
		{
			cin>>a;
			
			if(b!=0)
			koszt.push_back(a-b);
			
			b=a;
		}
		
		if(te==1)
		spr(0,0,1);
		else
		spr(1,0,1);
		
		cout<<ans<<"\n";	
	}
	
}
