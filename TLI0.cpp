#include<bits/stdc++.h>
using namespace std;

long long N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>N>>M;
	
	long long x=2;
	
	while(M>1&&x*x<=M)
	{
		if(M%x==0)
		{
			if(N%x)
			{
				cout<<"NIE";
				return 0;
			}
			while(M%x==0)
			M/=x;
		}	
		x++;
	}
	
	if(M>1&&N%M)
	{
		cout<<"NIE";
		return 0;
	}
	
	cout<<"TAK";
}
