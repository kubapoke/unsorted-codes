#include<bits/stdc++.h>
using namespace std;

long long N, M, w;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>N>>M;
	
	w=min(N,M/2);
	
	M-=2*N;
	
	if(M>0)
	w+=M/4;
	
	cout<<w;
}
