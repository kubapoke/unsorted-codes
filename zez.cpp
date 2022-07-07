#include<bits/stdc++.h>
using namespace std;

int tab[300005], roz[300005], n, q, u, pocz, kon, l, r, w;
char c;

void bruh()
{
	for(int i=pocz; i<=kon; i++)
	roz[i]=tab[i+1]-tab[i];
	/*
	for(int i=pocz; i<=kon; i++)
	cout<<roz[i]<<" ";
	cout<<"\n";
	*/
	for(int i=pocz; i<=kon; i++)
	{
		l=i-1; r=i+1;
		while(roz[i]<0)
		{
			if(i==pocz||i==kon)
			{
				w+=roz[i]*(-1);
				roz[i]=0;
			}
			else if(roz[l]>0)
			{
				roz[l]--;
				roz[i]++;
				w++;
			}
			else
			{
				roz[r]--;
				roz[i]++;
				w++;
			}
		}
	}
}

//8 0
//6 3 1 4 7 10 6 5

//3 5 1 4 7 R 10 L 3 R 6 R 5 L 6

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>n>>q;
	pocz=100003; kon=100003+n-2;
	
	for(int i=pocz; i<=kon+1; i++)
	cin>>tab[i];
	
	bruh();
	
	cout<<w<<" ";
	
	for(int x=1; x<=q; x++)
	{
		cin>>c;
		w=0;
		if(c=='R')
		{
			kon++;
			cin>>tab[kon+1];
			bruh();	
		}
		else
		{
			pocz--;
			cin>>tab[pocz];
			bruh();		
		}
		cout<<w<<" ";
	}
	
}
