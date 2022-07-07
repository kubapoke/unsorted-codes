#include<bits/stdc++.h>
using namespace std;
//8 4 1 2 1 4 3 3 1 2 1 4 7 8 2 5 4 7
int N, Q, A, X, Y;
vector<int> wys[1001];
vector<int>::iterator x, y;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>N>>Q;
	
	for(int i=1; i<=N; i++)
	{
		cin>>A;
		wys[A].push_back(i);
	}
	
	for(int i=0; i<Q; i++)
	{
		int w=0;
		cin>>X>>Y;
		
		for(int j=1; j<=1000; j++)
		{
			if(wys[j].size()>0)
			{
				x=lower_bound(wys[j].begin(), wys[j].end(), X);
				y=lower_bound(wys[j].begin(), wys[j].end(), Y);
				if(x<=y&&x!=wys[j].end()&&*x<=Y)
				w++;
			}
		}
		
		cout<<w<<"\n";
		
	}
}
