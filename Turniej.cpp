#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M, k, x, y, w=0;
	
	cin>>N>>M>>k;
	
	M-=N;
	
	x=k-1;
	y=k+1;
	
	while(M>0)
	{
		w++;
		M--;
		
		if(x>0)
		{
			M-=(k-x);
			x--;
		}
		
		
		if(y<=N)
		{
			M-=(y-k);
			y++;
		}
		
		
	}
	
	cout<<w+1;
}
