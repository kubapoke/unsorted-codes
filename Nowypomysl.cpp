#include<iostream>
#include<cmath>
#include<math.h>
#include<iomanip>
#include<algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	register int a, b, q, x, y;
	register float w=0;
	register char c;
	
	cin>>x>>y;
	
	int tabx[256];
	int taby[256];
	
	for(int i=0; i<x; i++)
	for(int j=0; j<y; j++)
	{
		cin>>c;
		if(c!='0')
		{
			tabx[c]=x;
			taby[c]=y;
		}
	}
	
	for(int i=0; i<256; i++)
	{
		cout<<i<<" "<<tabx[i]<<" "<<taby[i]<<'\n';
	}
	
	/*
	cin>>q;
	
	for(int i=0; i<q; i++)
	{
		cin>>c>>a>>b;
		
		if(a==tabx[c]&&b==taby[c])
		w++;
	}
	
	cout<<w;*/
}
