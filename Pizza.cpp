#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	register int N, Q, A, B, C, count;
	
	cin>>N>>Q;
	
	register int tab[N+1];
	register int ct[Q];
	
	for(register int i=1; i<=N; i++)
	cin>>tab[i];
	
	for(register int i=0; i<Q; i++)
	{
		count=0;
		cin>>A>>B>>C;
		
		for(register int j=A; j<=B; j++)
		{
			if(tab[j]%C==0)
			count++;
		}
		
		ct[i]=count;
	}
	
	for(register int i=0; i<Q; i++)
	{
		cout<<ct[i]<<"\n";
	}
	
}
