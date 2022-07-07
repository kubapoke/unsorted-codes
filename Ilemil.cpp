#include<bits/stdc++.h>
using namespace std;

long long sum;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	for(int i=1; i<=1e6; i++)
	sum+=1e6/i;
	
	cout<<sum;
}
