#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	for(int i=1; i<=100; i++)
	{
		cout<<i<<" => ";
		for(int j=1; j<=(i-j); j++)
		cout<<(j*(i-j)+2*i)<<" ";
		cout<<"\n";
	}
}
