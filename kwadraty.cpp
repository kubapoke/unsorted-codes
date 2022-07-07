#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int i=1;
	
	while(1)
	{
		if(i*i>999999)
		break;
		
		cout<<i<<" "<<i*i<<"\n";
		i++;
	}
}
