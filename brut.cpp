#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	for(int i=1; i<=100; i++)
	{
		cout<<i<<" => ";
		
		for(int j=1; j<=100; j++)
		for(int k=1; k<=100; k++)
		if(i==j*k+2*(j+k))
		cout<<j<<" "<<k<<"   ";
		cout<<"\n";
	}
}
