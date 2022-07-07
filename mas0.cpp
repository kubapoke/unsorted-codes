#include<bits/stdc++.h>
using namespace std;

//3 4 2 3 4 5 6 2 3 5 6 7 2 3 4 5 8 3 2 1 3

int N, Q, q, pq, w=10, ile;
int ks[100001][5], qs[100000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>N>>Q;
	
	for(int i=1; i<=N; i++)
	for(int j=0; j<5; j++)
	cin>>ks[i][j];
	
	for(int i=0; i<Q; i++)
	{
		pq=q;
		cin>>q;
		qs[i]=q;
		ile=0;
		
		if(i!=0)
		{
			w+=10;
			for(int j=0; j<5; j++)
			{
				if(ks[q][j]==ks[pq][j])
				{
					ile++;
				}
				else break;
			}
			w-=2*ile;
		}
	}
	
	cout<<w<<"\n";
	
	for(int i=0; i<Q; i++)
	{
		pq=q;
		q=qs[i];
		ile=0;
		
		if(i!=0)
		{
			for(int j=0; j<5; j++)
			{
				if(ks[q][j]==ks[pq][j])
				{
					ile++;
				}
				else break;
			}
			
			for(int j=0; j<5-ile; j++)
			cout<<0<<"\n";
			for(int j=ile; j<5; j++)
			cout<<1<<" "<<ks[q][j]<<"\n";
		}
		else
		for(int j=0; j<5; j++)
		cout<<1<<" "<<ks[q][j]<<"\n";
	}
	
	for(int i=0; i<5; i++)
	cout<<0<<"\n";
	
	
}
