#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	register int N, K, w=0, x;
	
	cin>>N>>K;
	
	int sztab[N];
	int kat[K];
	
	for(int i=0; i<N; i++)
	cin>>sztab[i];
	
	for(int i=0; i<=N-K; i++)
	{
		for(int j=0; j<K; j++)
		{
			kat[j]=sztab[j+i];
		}
		
		sort(kat, kat+K);
		
		x=kat[K/2];
		
		if(x>w)
		w=x;
	}
	
	cout<<w;
}
