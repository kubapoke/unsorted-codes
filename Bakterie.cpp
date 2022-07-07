#include<bits/stdc++.h>
using namespace std;

int main()
{
	for(int bezrozm=1; bezrozm<=6; bezrozm++)
	{
		cout<<bezrozm<<"/\n";
		int sum=1, pre=1, rozm;
		for(int i=1; i<=6; i++)
		{
			rozm=2*pre;
			
			if(i==bezrozm)
			rozm-=2;
			
			sum+=rozm;
			pre=rozm;
			
			cout<<i<<": "<<sum<<"\n";
		}
		cout<<"\n";
	}
}
